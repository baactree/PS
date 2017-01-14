#include "bits/stdc++.h"
using namespace std;
int N, M;
int fx, fy;
int cache[20][20];
int search(int x, int y) {
	if (x > fx || y > fy)
		return 0;
	if (x == fx&&y == fy)
		return 1;
	int &ret = cache[x][y];
	if (ret != -1)
		return ret;
	ret = search(x + 1, y);
	ret += search(x, y + 1);
	return ret;
}
int main() {
	int K;
	cin >> N >> M >> K;
	if (K == 0) {
		memset(cache, -1, sizeof(cache));
		fx = N - 1;
		fy = M - 1;
		printf("%d\n", search(0, 0));
	}
	else {
		memset(cache, -1, sizeof(cache));
		K--;
		fx = K / M;
		fy = K%M;
		int temp = search(0, 0);
		memset(cache, -1, sizeof(cache));
		fx = N - 1;
		fy = M - 1;
		printf("%d\n", temp*search(K / M, K%M));
	}
	return 0;
}