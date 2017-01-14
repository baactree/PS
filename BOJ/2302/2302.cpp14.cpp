#include "bits/stdc++.h"
using namespace std;
int N;
bool arr[41];
int cache[40][2][2];
int search(int idx, int pre, int now) {
	if (idx == N)
		return 1;
	int &ret = cache[idx][pre][now];
	if (ret != -1)
		return ret;
	ret = 0;
	if (arr[idx]) {
		if(pre&&!now)
			return ret = search(idx + 1, 1, 0);
		return 0;
	}
	if (!pre)
		return ret = search(idx + 1, now, 0);
	if (!now) 
		ret += search(idx + 1, 1, 0);
	if(idx!=N-1)
		ret += search(idx + 1, now, 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int in;
		scanf("%d", &in);
		arr[in-1] = true;
	}
	printf("%d\n", search(0, 1, 0));
	return 0;
}