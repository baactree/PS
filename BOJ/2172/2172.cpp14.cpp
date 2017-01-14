#include "bits/stdc++.h"
using namespace std;
int N, L;
int cache[20][20][20][20][20];
int Map[20][20];
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
bool safe(int x, int y) {
	return (x >= 0 && x < N&&y >= 0 && y < N);
}
int search(int sx, int sy, int len, int fx, int fy) {
	if (len == 0)
		return 1;
	int &ret = cache[sx][sy][len][fx][fy];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 8; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if (safe(nx, ny)) {
			for (int k = 0; k < 8; k++) {
				int tx = fx + dx[k];
				int ty = fy + dy[k];
				if (safe(tx, ty) && Map[tx][ty] == Map[nx][ny])
					ret+=search(nx, ny, len - 2, tx, ty);
			}
		}
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	int ans = 0;
	if (L & 1) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans+=search(i, j, L - 1, i, j);
	}
	else {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 8; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (safe(tx, ty) && Map[tx][ty] == Map[i][j])
						ans+=search(i, j, L - 2, tx, ty);
				}
			}
	}
	printf("%d\n", ans);
}