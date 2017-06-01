// =====================================================================================
// 
//       Filename:  5558.cpp
//        Created:  2017년 06월 02일 02시 00분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char mat[1000][1005];
int trip[1000][1000];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	int sx, sy;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]=='S'){
				sx=i;
				sy=j;
			}
	memset(trip, -1, sizeof(trip));
	queue<pair<int, int> > q;
	q.push({sx, sy});
	trip[sx][sy]=0;
	int now=0;
	int ans=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(mat[x][y]==now+1+'0'){
			if(mat[x][y]==k+'0'){
				ans+=trip[x][y];
				break;
			}
			ans+=trip[x][y];
			memset(trip, -1, sizeof(trip));
			trip[x][y]=0;
			now++;
			while(!q.empty())
				q.pop();
			q.push({x, y});
			continue;
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx, ny)&&mat[nx][ny]!='X'&&trip[nx][ny]==-1){
				trip[nx][ny]=trip[x][y]+1;
				q.push({nx, ny});
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

