#include "bits/stdc++.h"
using namespace std;
#define mod 100000
int N, M;
int cache[100][100][2][2];
int _search(int x, int y,bool turn,bool dir) {
	if (x == N - 1 && y == M - 1)
		return 1;
	int &ret = cache[x][y][turn][dir];
	if (ret != -1)
		return ret;
	ret = 0;
	if (turn) {
		if (dir) {
			if (x < N - 1)
				ret = _search(x + 1, y, false, true);
			return ret;
		}
		if (y < M - 1)
			ret = _search(x, y + 1, false, false);
		return ret;	
	}
	if (x == 0 && y == 0) {
		ret = _search(x + 1, y, false, true);
		ret += _search(x, y + 1, false, false);
		ret %= mod;
		return ret;
	}
	if (dir) {
		if (x < N - 1)
			ret += _search(x + 1, y, false, true);
		ret %= mod;
		if (y < M - 1)
			ret += _search(x, y + 1, true, false);
		return ret%=mod;
	}
	if (x < N - 1)
		ret += _search(x + 1, y, true, true);
	ret %= mod;
	if (y < M - 1)
		ret += _search(x, y + 1, false, false);
	return ret%=mod;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> M >> N;
	printf("%d\n", _search(0, 0,0,0));
	return 0;
}