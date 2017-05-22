// =====================================================================================
// 
//       Filename:  9376.cpp
//        Created:  2017년 05월 22일 14시 32분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int cnt, x, y, s;
	bool operator < (const Node &rhs)const{
		return cnt>rhs.cnt;
	}
};

char mat[105][105];
int h, w;
int sum[105][105];
int dist[105][105];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
const int inf=0x3f3f3f3f;
bool safe(int x, int y){
	return x>=0&&x<h+2&&y>=0&&y<w+2;
}
void dijk(const pair<int, int> &st){
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int, pair<int, int> > > pq;
	pq.push({0, {st.first, st.second}});
	dist[st.first][st.second]=0;
	while(!pq.empty()){
		int nx=pq.top().second.first;
		int ny=pq.top().second.second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[nx][ny]<cost)
			continue;
		for(int i=0;i<4;i++){
			int tx=nx+dx[i];
			int ty=ny+dy[i];
			if(!safe(tx, ty)||mat[tx][ty]=='*')
				continue;
			int there_cost=cost+(mat[tx][ty]=='#');
			if(dist[tx][ty]>there_cost){
				dist[tx][ty]=there_cost;
				pq.push({-there_cost, {tx, ty}});
			}
		}
	}
	for(int i=0;i<h+2;i++){
		for(int j=0;j<w+2;j++){
			sum[i][j]=min(inf, sum[i][j]+dist[i][j]);
		}
	}
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		memset(mat, 0, sizeof(mat));
		scanf("%d%d", &h, &w);
		for(int i=0;i<h;i++)
			scanf("%s", &mat[i+1][1]);
		memset(sum, 0, sizeof(sum));
		vector<pair<int, int> > st;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				if(mat[i][j]=='$')
					st.push_back({i, j});
		st.push_back({0, 0});
		for(int i=0;i<st.size();i++)
			dijk(st[i]);
		int ans=inf;
		for(int i=0;i<h+2;i++)
			for(int j=0;j<w+2;j++){
				if(mat[i][j]=='#')
					sum[i][j]-=2;
				ans=min(ans, sum[i][j]);
			}
		printf("%d\n", ans);
	}
	return 0;
}

