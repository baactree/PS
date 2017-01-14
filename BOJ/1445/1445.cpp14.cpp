#include <bits/stdc++.h>
using namespace std;
int N, M;
char mat[50][51];
pair<int, int> dist[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < M;
}
int main() {
	memset(dist, 0x3f, sizeof(dist));
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
	int fx, fy;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] == 'g') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (safe(nx, ny) && mat[nx][ny] == '.') {
						mat[nx][ny] = 'c';
					}
				}
			}
			else if (mat[i][j] == 'S') {
				pq.push({ {0,0},{i,j} });
				dist[i][j] = { 0,0 };
			}
			else if (mat[i][j] == 'F') {
				fx = i, fy = j;
			}
	while (!pq.empty()) {
		int nx = pq.top().second.first;
		int ny = pq.top().second.second;
		pair<int, int> cost = { -pq.top().first.first,-pq.top().first.second };
		pq.pop();
		if (dist[nx][ny] < cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty)) {
				pair<int, int> there_cost = { cost.first + (mat[tx][ty] == 'g'),cost.second + (mat[tx][ty] == 'c') };
				if (dist[tx][ty]>there_cost) {
					dist[tx][ty] = there_cost;
					pq.push({ {-there_cost.first,-there_cost.second},{tx,ty} });
				}
			}
		}
	}
	printf("%d %d\n", dist[fx][fy].first, dist[fx][fy].second);
	return 0;
}
