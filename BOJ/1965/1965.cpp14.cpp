#include "bits/stdc++.h"
using namespace std;
int arr[1001];
int cache[1001][1001];
int N;
int search(int idx, int pre) {
	if (idx == N + 1)
		return 0;
	int &ret = cache[idx][pre];
	if (ret != -1)
		return ret;
	ret = search(idx + 1, pre);
	if (arr[idx] > arr[pre])
		ret = max(ret, search(idx + 1, idx) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", search(1,0));
	return 0;
}