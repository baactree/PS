#include "bits/stdc++.h"
using namespace std;
int Map[100][100];
bool trip[100][100][4];
struct dat {
	int x, y, dir, cnt;
};
int N, M;
queue<dat> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool safe(int x, int y) {
	return (x >= 0 && x < N&&y >= 0 && y < M);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &Map[i][j]);
	int sx, sy, sdir, fx, fy, fdir;
	scanf("%d%d%d%d%d%d", &sx, &sy, &sdir, &fx, &fy, &fdir);
	sx--; sy--; sdir--; fx--; fy--; fdir--;
	dat temp;
	temp.x = sx; temp.y = sy; temp.dir = sdir; temp.cnt = 0;
	q.push(temp);
	trip[sx][sy][sdir] = true;
	int ans;
	while (!q.empty()) {
		int nx, ny, ndir, ncnt;
		nx = q.front().x;
		ny = q.front().y;
		ndir = q.front().dir;
		ncnt = q.front().cnt;
		q.pop();
		if (nx == fx&&ny == fy&&ndir == fdir) {
			ans = ncnt;
			break;
		}
		if (ndir == 0 || ndir == 1) {
			if (!trip[nx][ny][3]) {
				trip[nx][ny][3] = true;
				temp.x = nx; temp.y = ny; temp.dir = 3; temp.cnt = ncnt + 1;
				q.push(temp);
			}
			if (!trip[nx][ny][2]) {
				trip[nx][ny][2] = true;
				temp.x = nx; temp.y = ny; temp.dir = 2; temp.cnt = ncnt + 1;
				q.push(temp);
			}
		}
		else if (ndir == 2 || ndir == 3) {
			if (!trip[nx][ny][0]) {
				trip[nx][ny][0] = true;
				temp.x = nx; temp.y = ny; temp.dir = 0; temp.cnt = ncnt + 1;
				q.push(temp);
			}
			if (!trip[nx][ny][1]) {
				trip[nx][ny][1] = true;
				temp.x = nx; temp.y = ny; temp.dir = 1; temp.cnt = ncnt + 1;
				q.push(temp);
			}
		}

		for (int i = 0; i < 4; i++) {
			if (ndir != i)
				continue;
			for (int k = 1; k <= 3; k++) {
				int tx = nx + dx[i] * k;
				int ty = ny + dy[i] * k;
				if (Map[tx][ty] == 1)
					break;
				if (safe(tx, ty) && !trip[tx][ty][ndir]) {
					trip[tx][ty][ndir] = true;
					temp.x = tx; temp.y = ty; temp.dir = ndir; temp.cnt = ncnt + 1;
					q.push(temp);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}