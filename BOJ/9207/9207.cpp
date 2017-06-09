// =====================================================================================
// 
//       Filename:  9207.cpp
//        Created:  2017년 06월 09일 16시 30분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char mat[5][10];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<5&&y>=0&&y<9;
}
pair<int, int> solve(int cnt){
	vector<pair<int, int> > p;
	for(int i=0;i<5;i++){
		for(int j=0;j<9;j++){
			if(mat[i][j]=='o')
				p.push_back({i, j});
		}
	}
	pair<int, int> ret={p.size(), cnt};
	for(int i=0;i<p.size();i++){
		int x=p[i].first;
		int y=p[i].second;
		for(int j=0;j<4;j++){
			int nx=x+dx[j];
			int ny=y+dy[j];
			int kx=nx+dx[j];
			int ky=ny+dy[j];
			if(safe(nx, ny)&&mat[nx][ny]=='o'&&safe(kx, ky)&&mat[kx][ky]=='.'){
				mat[x][y]='.';
				mat[nx][ny]='.';
				mat[kx][ky]='o';
				ret=min(ret, solve(cnt+1));
				mat[x][y]='o';
				mat[nx][ny]='o';
				mat[kx][ky]='.';
			}
		}
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<5;i++)
			scanf("%s", mat[i]);
		auto ans=solve(0);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}

