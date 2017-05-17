// =====================================================================================
// 
//       Filename:  13903.cpp
//        Created:  2017년 05월 16일 19시 10분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c;
int mat[1000][1000];
int dist[1000][1000];
int n;
int dx[10];
int dy[10];
bool safe(int x, int y){
	return x>=0&&x<r&&y>=0&&y<c;
}
int main(){
	memset(dist, 0x3f, sizeof(dist));
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d", &mat[i][j]);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		dx[i]=a;
		dy[i]=b;
	}
	queue<pair<int, int> > q;
	for(int i=0;i<c;i++)
		if(mat[0][i]==1){
			q.push({0, i});
			dist[0][i]=0;
		}
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<n;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx, ny)&&mat[nx][ny]==1&&dist[nx][ny]==0x3f3f3f3f){
				dist[nx][ny]=dist[x][y]+1;
				q.push({nx, ny});
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<c;i++){
		ans=min(ans, dist[r-1][i]);
	}
	printf("%d\n", ans==0x3f3f3f3f?-1:ans);
	return 0;
}

