#include "bits/stdc++.h"
using namespace std;
int Map[999][999];
bool trip[999][999];
int N, K;
pair<int, int> ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool safe(int x, int y) {
	return (x >= 0 && x < N&&y >= 0 && y < N);
}
void search(int x, int y, int cnt,int dir) {
	if (cnt == K)
		ans = make_pair(x+1, y+1);
	Map[x][y] = cnt;
	trip[x][y] = true;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (safe(nx, ny) && !trip[nx][ny])
		search(nx, ny, cnt - 1, dir);
	dir++;
	dir %= 4;
	 nx = x + dx[dir];
	 ny = y + dy[dir];
	if (safe(nx, ny) && !trip[nx][ny])
		search(nx, ny, cnt - 1, dir);
}
int main() {
	scanf("%d%d", &N,&K);
	search(0, 0, N*N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", Map[i][j]);
		printf("\n");
	}
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}