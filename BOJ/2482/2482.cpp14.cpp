#include "bits/stdc++.h"
using namespace std;
#define X 1000000003
int N, K;
int cache[1000][1001][2];
int search(int idx, int k, bool upper) {
	if (idx == N) {
		if (k == K)
			return 1;
		return 0;
	}
	int &ret = cache[idx][k][upper];
	if (ret != -1)
		return ret;
	ret = 0;
	if(!upper)
		ret = (ret+search(idx + 1, k + 1, true))%X;
	ret = (ret+search(idx + 1, k, false))%X;
	return ret;
}
int _search(int idx, int k, bool upper) {
	if (idx == N - 1) {
		if (k == K)
			return 1;
		return 0;
	}
	int &ret = cache[idx][k][upper];
	if (ret != -1)
		return ret;
	ret = 0;
	if(!upper)
		ret = (ret+_search(idx + 1, k + 1, true))%X;
	ret = (ret+_search(idx + 1, k, false))%X;
	return ret;
}
int main() {
	cin >> N >> K;
	memset(cache, -1, sizeof(cache));
	int ans = _search(1, 1, 1)%X;
	memset(cache, -1, sizeof(cache));
	ans = (ans + search(1, 0, 0)) % X;
	printf("%d\n", ans);
	return 0;
}