#include "bits/stdc++.h"
using namespace std;
int cache[501][501];
int search(int n, int k) {
	if (k == 1 || n <= 1)
		return n;
	int &ret = cache[n][k];
	if (ret != -1)
		return ret;
	ret = 0x7fffffff;
	for (int i = 1; i <= n; i++)
		ret = min(ret, max(search(n - i, k) + 1, search(i - 1, k - 1) + 1));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int N, K;
	cin >> N >> K;
	printf("%d\n", search(N, K));
	return 0;
}