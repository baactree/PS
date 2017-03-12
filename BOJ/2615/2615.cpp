// =====================================================================================
// 
//       Filename:  2615.cpp
//        Created:  2017년 03월 12일 18시 09분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[19][19];
int dx[4]={-1, 0, 1, 1};
int dy[4]={1, 1, 1, 0};
bool safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<19;
}
bool possi(int x, int y){
	for(int i=0;i<4;i++){
		int cnt=0;
		for(int j=1;j<=5;j++){
			int nx=x+dx[i]*j;
			int ny=y+dy[i]*j;
			if(safe(nx, ny)&&mat[x][y]==mat[nx][ny])
				cnt++;
			else
				break;
		}	
		if(cnt==4){
			if(!safe(x-dx[i], y-dy[i])||mat[x][y]!=mat[x-dx[i]][y-dy[i]])
				return true;
		}
	}
	return false;
}
int main(){
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++){
			if(mat[i][j]&&possi(i, j)){
				printf("%d\n", mat[i][j]);
				printf("%d %d\n", i+1, j+1);
				return 0;
			}
		}
	printf("0\n");
	return 0;
}

