// =====================================================================================
// 
//       Filename:  2210.cpp
//        Created:  2017년 05월 22일 17시 25분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[5][5];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<5;
}
set<string> s;
void solve(int x, int y, int idx, string str){
	if(idx==5){
		s.insert(str);
		return;
	}
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)){
			solve(nx, ny, idx+1, str+to_string(mat[nx][ny]));
		}
	}
}
int main(){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			solve(i, j, 0, to_string(mat[i][j]));
	printf("%d\n", s.size());
	return 0;
}

