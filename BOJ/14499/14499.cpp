// =====================================================================================
// 
//       Filename:  14499.cpp
//        Created:  2017년 04월 11일 00시 46분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y;
int k;
int mat[20][20];
// 1 2 3 4 5 6
int dice[7]={0, 0, 0, 0, 0, 0, 0};
int dx[4]={0, 0, -1, 1};
int dy[4]={1, -1, 0, 0};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int main(){
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<k;i++){
		int order;
		scanf("%d", &order);
		order--;
		int nx=x+dx[order];
		int ny=y+dy[order];
		if(!safe(nx, ny))
			continue;
		int ndice[7]={0, };
		if(order==0){
			ndice[3]=dice[1];
			ndice[1]=dice[4];
			ndice[4]=dice[6];
			ndice[6]=dice[3];
			ndice[2]=dice[2];
			ndice[5]=dice[5];
		}
		if(order==1){
			ndice[1]=dice[3];
			ndice[3]=dice[6];
			ndice[6]=dice[4];
			ndice[4]=dice[1];
			ndice[2]=dice[2];
			ndice[5]=dice[5];
		}
		if(order==2){
			ndice[1]=dice[5];
			ndice[5]=dice[6];
			ndice[6]=dice[2];
			ndice[2]=dice[1];
			ndice[3]=dice[3];
			ndice[4]=dice[4];
		}
		if(order==3){
			ndice[1]=dice[2];
			ndice[2]=dice[6];
			ndice[6]=dice[5];
			ndice[5]=dice[1];
			ndice[3]=dice[3];
			ndice[4]=dice[4];
		}
		if(mat[nx][ny]==0){
			mat[nx][ny]=ndice[6];
		}
		else{
			ndice[6]=mat[nx][ny];
			mat[nx][ny]=0;
		}
		printf("%d\n", ndice[1]);
		for(int i=0;i<7;i++)
			dice[i]=ndice[i];
		x=nx;
		y=ny;
	}
	return 0;
}

