#include "bits/stdc++.h"
using namespace std;
int N, M;
int stx, sty, fix, fiy;
bool trip[8][8];
pair<int, int> ans[64];
bool flag;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int nx, ny;
bool possi(){
	int a = (stx + sty) % 2;
    int b = (fix + fiy) % 2;
	return a != b;
}
void search(int x, int y, int idx) {
	if (flag)
		return;
	trip[x][y] = true;
	ans[idx].first = x, ans[idx].second = y;
	if (x == fix&&y == fiy) {
		if (idx + 1 == N*M)
			flag = true;
		trip[x][y] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if ((nx >= 0 && nx < N&&ny >= 0 && ny < M) && !trip[nx][ny])
			search(nx, ny, idx + 1);
	}
	trip[x][y] = false;
	return;
}
int main() {
	int Case;
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d%d%d%d%d%d", &N, &M, &stx, &sty, &fix, &fiy);
		if (!possi()) {
			printf("-1\n");
			continue;
		}
		stx--, sty--, fix--, fiy--;
		flag = false;
		memset(trip, 0, sizeof(trip));
		search(stx, sty, 0);
		if (!flag)
			printf("-1\n");
		else {
			printf("1\n");
			for (int i = 0; i <N*M; i++)
				printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}
}
