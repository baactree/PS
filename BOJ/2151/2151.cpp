// =====================================================================================
// 
//       Filename:  2151.cpp
//        Created:  2017년 07월 31일 22시 41분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char mat[55][55];
int dist[50][50][4];
int dx[4]={-1, 0, 0, 1};
int dy[4]={0, -1, 1, 0};
bool safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<n;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	vector<pair<int, int> > vec;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mat[i][j]=='#')
				vec.push_back({i, j});
	memset(dist, 0x3f, sizeof(dist));
	int sx, sy;
	sx=vec[0].first;
	sy=vec[0].second;
	priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
	for(int i=0;i<4;i++){
		pq.push({{0, i}, {sx, sy}});
		dist[sx][sy][i]=0;
	}
	while(!pq.empty()){
		int x=pq.top().second.first;
		int y=pq.top().second.second;
		int dir=pq.top().first.second;
		int cost=-pq.top().first.first;
		pq.pop();
		if(dist[x][y][dir]<cost)
			continue;
		if(mat[x][y]=='!'){
			for(int i=0;i<4;i++){
				if(i==3-dir)
					continue;
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(safe(nx, ny)&&mat[nx][ny]!='*'){
					int there_cost=cost+(i!=dir);
					if(dist[nx][ny][i]>there_cost){
						dist[nx][ny][i]=there_cost;
						pq.push({ {-there_cost, i}, {nx, ny} });
					}
				}
			}
		}
		else{
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			if(safe(nx, ny)&&mat[nx][ny]!='*'){
				int there_cost=cost;
				if(dist[nx][ny][dir]>there_cost){
					dist[nx][ny][dir]=there_cost;
					pq.push({ {-there_cost, dir}, {nx, ny}});
				}
			}
		}
	}
	int fx, fy;
	fx=vec[1].first;
	fy=vec[1].second;
	int ans=0x3f3f3f3f;
	for(int i=0;i<4;i++)
		ans=min(ans, dist[fx][fy][i]);
	printf("%d\n", ans);
	return 0;
}

