// =====================================================================================
// 
//       Filename:  1303.cpp
//        Created:  2017년 04월 14일 10시 42분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[100][101];
int b, w;
int trip[100][100];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int dfs(int x, int y, char now){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&!trip[nx][ny]&&mat[nx][ny]==now)
			ret+=dfs(nx, ny, now);
	}
	return ret;
}
int main(){
	scanf("%d%d", &m, &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!trip[i][j]){
				if(mat[i][j]=='W'){
					int temp=dfs(i, j, 'W');
					w+=temp*temp;
				}
				else{
					int temp=dfs(i, j, 'B');
					b+=temp*temp;
				}
			}
	printf("%d %d\n", w, b);
	return 0;
}

