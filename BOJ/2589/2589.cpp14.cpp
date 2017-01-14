#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int N, M;
char Map[50][51];
bool trip[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct _data {
	int x;
	int y;
	int dist;
	_data(int x, int y, int dist) {
		this->x = x;
		this->y = y;
		this->dist = dist;
	}
};
bool safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&&y < M);
}
int search(int x, int y) {
	int dist = 0;
	queue<_data*> q;
	q.push(new _data(x,y,0));
	trip[x][y] = true;
	while (!q.empty()) {
		
		int nx = q.front()->x;
		int ny = q.front()->y;
		int nd = q.front()->dist;
		delete q.front();
		q.pop();
		dist = max(dist, nd);
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty) && Map[tx][ty] == 'L'&&!trip[tx][ty]) {
				trip[tx][ty] = true;
				q.push(new _data(tx, ty, nd + 1));
			}
		}
	}
	return dist;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%s", Map[i]);
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M;j++)
			if (Map[i][j] == 'L') {
				memset(trip, 0, sizeof(trip));
				ans=max(ans,search(i, j));
			}
	printf("%d\n", ans);
	return 0;
}