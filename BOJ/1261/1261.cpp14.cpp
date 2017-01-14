#include "bits/stdc++.h"
using namespace std;
int N, M;
char Map[100][101];
bool trip[100][100];
bool breeeak[100][100];
bool safe(int x, int y) {
	return (x >= 0 && x < N&&y >= 0 && y < M);
}
queue<pair<int, int> >q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void search(int x, int y) {
	q.push(make_pair(x, y));
	trip[x][y] = true;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		if (Map[nx][ny] == '1') {
			breeeak[nx][ny] = true;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty) && !trip[tx][ty]) {
				trip[tx][ty] = true;
				q.push(make_pair(tx, ty));
			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		scanf("%s", Map[i]);
	int ans = -1;
	while (!trip[N - 1][M - 1]) {
		memset(trip, 0, sizeof(trip));
		memset(breeeak, 0, sizeof(breeeak));
		ans++;
		search(0, 0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (breeeak[i][j])
					Map[i][j] = '0';
	}
	printf("%d\n", ans);
}