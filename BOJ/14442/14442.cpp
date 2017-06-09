// =====================================================================================
// 
//       Filename:  14442.cpp
//        Created:  2017년 06월 09일 16시 14분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char mat[1000][1005];
int dist[1000][1000][11];
struct Node{
	int x, y, k;
};
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	queue<Node> q;
	q.push({0, 0, 0});
	memset(dist, 0x3f, sizeof(dist));
	dist[0][0][0]=0;
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		int w=q.front().k;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx, ny)){
				if(mat[nx][ny]=='0'&&dist[nx][ny][w]==inf){
					dist[nx][ny][w]=dist[x][y][w]+1;
					q.push({nx, ny, w});
				}
				if(mat[nx][ny]=='1'&&w<k&&dist[nx][ny][w+1]==inf){
					dist[nx][ny][w+1]=dist[x][y][w]+1;
					q.push({nx, ny, w+1});
				}
			}
		}
	}
	int ans=inf;
	for(int i=0;i<=k;i++)
		ans=min(ans, dist[n-1][m-1][i]);
	printf("%d\n", ans==inf?-1:ans+1);
	return 0;
}

