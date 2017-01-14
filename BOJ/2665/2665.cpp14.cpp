#include "bits/stdc++.h"
using namespace std;
char Map[50][51];
bool Break[50][50];
bool trip[50][50];
int N;
queue<pair<int, int> > q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return (x >= 0 && x < N&&y >= 0 && y < N);
}
void search(int x, int y) {
	trip[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		if (Map[nx][ny] == '0') {
			Break[nx][ny] = true;
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
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%s", &Map[i]);
	int ans = -1;
	while (!trip[N - 1][N - 1]) {
		memset(trip, 0, sizeof(trip));
		memset(Break, 0, sizeof(Break));
		ans++;
		search(0, 0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (Break[i][j])
					Map[i][j] = '1';
	}
	printf("%d\n", ans);
	return 0;
}