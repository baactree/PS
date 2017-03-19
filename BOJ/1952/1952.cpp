// =====================================================================================
// 
//       Filename:  1952.cpp
//        Created:  2017년 03월 19일 19시 44분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
bool trip[100][100];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int solve(int x, int y, int dir){
	trip[x][y]=true;
	int nx=x+dx[dir];
	int ny=y+dy[dir];
	int ret=0;
	if(!safe(nx, ny)||trip[nx][ny]){
		dir++;
		ret++;
	}
	dir%=4;
	nx=x+dx[dir];
	ny=y+dy[dir];
	if(safe(nx, ny)&&!trip[nx][ny])
		ret+=solve(nx, ny, dir);
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	printf("%d\n", solve(0, 0, 0)-1);
	return 0;
}

