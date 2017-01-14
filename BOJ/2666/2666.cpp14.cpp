#include "bits/stdc++.h"
using namespace std;
int N,K;
int cache[20][21][21];
int arr[20];
int search(int idx, int left, int right) {
	if (idx == K)
		return 0;
	int &ret = cache[idx][left][right];
	if (ret != -1)
		return ret;
	ret = search(idx + 1, arr[idx], right) + abs(left - arr[idx]);
	ret = min(ret, search(idx + 1, left, arr[idx]) + abs(right - arr[idx]));
	return ret;
}
main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int a, b;
	scanf("%d%d", &a, &b);
	cin >> K;
	for (int i = 0; i < K; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", search(0, a, b));
	return 0;
}