// =====================================================================================
// 
//       Filename:  1600.cpp
//        Created:  2017년 05월 10일 19시 14분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int mat[20][20];
int dist[20][20][22];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
struct Node{
	int x, y, k;
};
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d", &mat[i][j]);
		memset(dist, -1, sizeof(dist));
		queue<Node> q;
		q.push({0, 0, 0});
		dist[0][0][0]=0;
		int ans=-1;
		while(!q.empty()){
			int x=q.front().x;
			int y=q.front().y;
			int cnt=q.front().k;
			q.pop();
			if(x==n-1&&y==m-1){
				ans=dist[x][y][cnt];
				break;
			}
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(safe(nx, ny)){
					if(mat[nx][ny]==0&&dist[nx][ny][0]==-1){
						dist[nx][ny][0]=dist[x][y][cnt]+1;
						q.push({nx, ny, 0});
					}
					else if(mat[nx][ny]==1&&cnt<k&&dist[nx][ny][cnt+1]==-1){
						dist[nx][ny][cnt+1]=dist[x][y][cnt]+1;
						q.push({nx, ny, cnt+1});
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

