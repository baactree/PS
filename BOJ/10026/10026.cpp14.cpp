#include "bits/stdc++.h"
using namespace std;
int N;
char Map[100][101];
int trip[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return (x >= 0 && x < N&&y >= 0 && y < N);
}

void search(int x, int y) {
	trip[x][y] = true;
	char now = Map[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && now == Map[nx][ny]&&!trip[nx][ny])
			search(nx, ny);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%s", Map[i]);
	int rgb = 0;
	int gb = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N;j++)
			if (!trip[i][j]) {
				rgb++;
				search(i, j);
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 'G')
				Map[i][j] = 'R';
	memset(trip, 0, sizeof(trip));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N;j++)
			if (!trip[i][j]) {
				gb++;
				search(i, j);
			}
	printf("%d %d\n", rgb, gb);
	return 0;
}