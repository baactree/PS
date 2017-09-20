// =====================================================================================
// 
//       Filename:  14716.cpp
//        Created:  2017년 09월 19일 21시 38분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int mat[300][300];
bool trip[300][300];
void dfs(int x, int y){
	trip[x][y]=true;
	for(int i=0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]&&!trip[nx][ny])
			dfs(nx, ny);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(mat[i][j]&&!trip[i][j]){
				dfs(i, j);
				ans++;
			}
		}
	printf("%d\n", ans);
	return 0;
}

