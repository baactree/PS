#include "bits/stdc++.h"
using namespace std;
int len;
int N;
int cache[1 << 20];
int arr[20];
bool search(int idx, int state,int leng) {
	if (idx == 4)
		return true;
	int &ret = cache[state];
	if (ret != -1)
		return ret;
	if (leng == len)
		return ret = search(idx + 1, state, 0);
	if (leng > len)
		return ret = false;
	for (int i = 0; i < N; i++) {
		if (state&(1 << i))
			continue;
		if (search(idx, state | (1 << i), leng + arr[i]))
			return ret = true;
	}
	return ret = false;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		len = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			len += arr[i];
		}
		if (len % 4 != 0) {
			printf("no\n");
			continue;
		}
		len /= 4;
		if (search(0, 0, 0))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}