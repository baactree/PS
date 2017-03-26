// =====================================================================================
// 
//       Filename:  1743.cpp
//        Created:  2017년 03월 26일 21시 08분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[101][101];
bool trip[101][101];
int n, m, k;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>0&&x<=n&&y>0&&y<=m;
}
int dfs(int x, int y){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]==1&&!trip[nx][ny]){
			ret+=dfs(nx, ny);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		mat[a][b]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mat[i][j]==1&&!trip[i][j])
				ans=max(ans, dfs(i, j));
	printf("%d\n", ans);
	return 0;
}

