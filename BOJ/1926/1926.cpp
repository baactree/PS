// =====================================================================================
// 
//       Filename:  1926.cpp
//        Created:  2017년 04월 03일 11시 28분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int mat[500][500];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool trip[500][500];
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int dfs(int x, int y){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&!trip[nx][ny]&&mat[nx][ny]==1){
			ret+=dfs(nx, ny);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	int ans=0;
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]&&!trip[i][j]){
				int now=dfs(i, j);
				ans=max(ans, now);
				cnt++;
			}
	printf("%d\n%d\n",cnt,  ans);
	return 0;
}

