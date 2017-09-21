// =====================================================================================
// 
//       Filename:  14497.cpp
//        Created:  2017년 09월 21일 09시 36분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int sx, sy, fx, fy;
char mat[305][305];
int dist[305][305];
vector<pair<int, int> > b;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
	sx--;sy--;fx--;fy--;
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	mat[sx][sy]='0';
	mat[fx][fy]='1';
	memset(dist, 0x3f, sizeof(dist));
	dist[sx][sy]=0;
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({0, {sx, sy}});
	while(!pq.empty()){
		int x=pq.top().second.first;
		int y=pq.top().second.second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[x][y]<cost)
			continue;
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx, ny)){
				int there_cost=cost+(mat[nx][ny]=='1'?1:0);
				if(dist[nx][ny]>there_cost){
					dist[nx][ny]=there_cost;
					pq.push({-there_cost, {nx, ny}});
				}
			}
		}
	}
	printf("%d\n", dist[fx][fy]);
	return 0;
}

