#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
using namespace std;
int N, M;
int Map[500][500];
int cache[500][500]; 
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&&y < M);
}
int search(int x, int y) {
	if (x == 0 && y == 0)
		return 1;
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && Map[nx][ny]>Map[x][y]) {
			ret += search(nx, ny);
		}
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &Map[i][j]);
	printf("%d\n", search(N - 1, M - 1));
	return 0;
}