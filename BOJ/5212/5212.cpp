// =====================================================================================
// 
//       Filename:  5212.cpp
//        Created:  2017년 05월 05일 11시 15분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int r, c;
char mat[10][11];
char nmat[10][11];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<r&&y>=0&&y<c;
}
bool possi(int x, int y){
	int ret=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(!safe(nx, ny)||mat[nx][ny]=='.')
			ret++;
	}
	return ret>=3;
}
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		scanf("%s", mat[i]);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			nmat[i][j]=mat[i][j];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(mat[i][j]=='X')
				if(possi(i, j))
					nmat[i][j]='.';
	int sx, sy, fx, fy;
	sx=inf;
	sy=inf;
	fx=-inf;
	fy=-inf;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(nmat[i][j]=='X'){
				sx=min(sx, i);
				sy=min(sy, j);
				fx=max(fx, i);
				fy=max(fy, j);
			}
	for(int i=sx;i<=fx;i++){
		for(int j=sy;j<=fy;j++)
			printf("%c", nmat[i][j]);
		printf("\n");
	}
	return 0;
}

