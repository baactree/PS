// =====================================================================================
// 
//       Filename:  1941.cpp
//        Created:  2017년 03월 27일 21시 20분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char mat[5][6];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool trip[5][5];
int perm[5][5];
bool safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<5;
}
int dfs(int x, int y){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&!trip[nx][ny]&&perm[nx][ny])
			ret+=dfs(nx, ny);
	}
	return ret;
}
int main(){
	for(int i=0;i<5;i++)
		scanf("%s", mat[i]);
	int ans=0;
	vector<int> state(25, 0);
	for(int i=0;i<7;i++)
		state[24-i]=1;
	
	do{
		memset(perm, 0, sizeof(perm));
		int ycnt=0;
		int sx, sy;
		for(int i=0;i<25;i++){
			int x=i/5;
			int y=i%5;
			perm[x][y]=state[i];
			if(state[i]){
				sx=x;
				sy=y;
				ycnt+=mat[x][y]=='Y';
			}
		}
		if(ycnt>=4)
			continue;
		memset(trip, 0, sizeof(trip));
		ans+=dfs(sx, sy)==7;
	}while(next_permutation(state.begin(), state.end()));
	printf("%d\n", ans);

	return 0;
}

