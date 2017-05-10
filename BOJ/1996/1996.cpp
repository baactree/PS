// =====================================================================================
// 
//       Filename:  1996.cpp
//        Created:  2017년 05월 05일 11시 21분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char mat[1000][1001];
char ans[1000][1000];
int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};
bool safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<n;
}
int find(int x, int y){
	int ret=0;
	for(int i=0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]!='.')
			ret+=mat[nx][ny]-'0';
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", &mat[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(mat[i][j]=='.'){
				int cnt=find(i, j);
				ans[i][j]=(cnt>=10?'M':(cnt+'0'));
			}
			else
				ans[i][j]='*';
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}

