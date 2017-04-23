// =====================================================================================
// 
//       Filename:  5913.cpp
//        Created:  2017년 04월 21일 11시 37분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[6][6];
int trip[6][6];
bool safe(int x, int y){
	return x>0&&x<=5&&y>0&&y<=5;
}
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int k;
int solve(int x, int y, int cnt){
	if(x==5&&y==5){
		return cnt==0;
	}
	trip[x][y]=true;
	int ret=0;

	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]==0&&!trip[nx][ny]){
			ret+=solve(nx, ny, cnt-1);
		}
	}
	trip[x][y]=false;
	return ret;
}
int main(){
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b]=1;
	}
	printf("%d\n", solve(1, 1, 24-k));
	return 0;
}

