#include "bits/stdc++.h"
using namespace std;
const int mod = 9901;
int N, M;
int cache[14 * 14][1 << 14];
int search(int n, int state) {
	if (n == N*M) {
		if (!state)
			return 1;
		return 0;
	}
	int &ret = cache[n][state];
	if (ret != -1)
		return ret;
	if (state & 1)
		return ret = search(n + 1, state >> 1);
	ret = 0;
	if (!(state & 2)&&n%M!=M-1)
		ret = (ret+search(n + 1, (state >> 1) | 1))%mod;
	ret = (ret+search(n + 1, (state >> 1) | (1 << (M-1))))%mod;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	if ((N*M) & 1) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", search(0, 0));
	return 0;
}