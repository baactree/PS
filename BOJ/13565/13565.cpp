// =====================================================================================
// 
//       Filename:  13565.cpp
//        Created:  2017년 05월 26일 00시 05분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[1000][1000];
bool trip[1000][1000];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int x, int y){
	if(trip[x][y])
		return;
	trip[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]==0)
			dfs(nx, ny);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d", &mat[i][j]);
	for(int i=0;i<m;i++)
		if(mat[0][i]==0&&!trip[0][i])
			dfs(0, i);
	bool flag=false;
	for(int i=0;i<m;i++)
		if(trip[n-1][i])
			flag=true;
	printf("%s\n", flag?"YES":"NO");
	return 0;
}

