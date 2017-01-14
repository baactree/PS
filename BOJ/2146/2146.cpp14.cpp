#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
int Map[100][100];
int cache[100][100];
int dist[100][100];
int N;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool safe(int x, int y){
	return (x >= 0 && x < N&&y >= 0 && y < N);
}
void dfs(int x, int y, int cnt){
	cache[x][y] = cnt;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && Map[nx][ny] == 1 && cache[nx][ny] == 0)
			dfs(nx, ny, cnt);
	}
}
int bridge = 1;
bool flag;
int Min = 987654321;
bool updated = false;
void search(int cnt){
	queue<pair<int,int> > q;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			if (cache[i][j] == cnt)
				q.push(make_pair(i, j));
	}
	int size = q.size();
	for (int i = 0; i < size; i++){
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++){
			int nx = tx + dx[j];
			int ny = ty + dy[j];
			if (safe(nx, ny) && cache[nx][ny] != 0 && cache[nx][ny] != cnt){
				Min = min(Min, dist[tx][ty] + dist[nx][ny]);
			}
			if (safe(nx, ny) && cache[nx][ny] == 0){
				cache[nx][ny] = cnt;
				q.push(make_pair(nx, ny));
				dist[nx][ny] = bridge;
				updated = true;
			}
		}
	}
}
int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	memset(cache, 0, sizeof(cache));
	int cnt = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 1 && cache[i][j] == 0)
				dfs(i, j, cnt++);
	}
	if (cnt <= 2){
		printf("0\n");
		return 0;
	}
	flag = false;
	while (true){
		updated = false;
		for (int i = 1; i < cnt; i++)
			search(i);
		
		bridge++;
		if (updated == false)
			break;
	}
	printf("%d\n", Min);
	return 0; 
}