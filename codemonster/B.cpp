// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 29일 11시 22분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
bool mat[505][505];
int cache[505][505][2];
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
int solve(int x, int y, int mode){
	if(!safe(x, y))
		return 0;
	if(x==n-1&&y==n-1){
		if(mode)
			return mat[x][y];
		else
			return 0;
	}
	int &ret=cache[x][y][mode];
	if(ret!=-1)
		return ret;
	if(x==0&&!mode)
		return ret=solve(x, y+1, 1)+mat[x][y];
	ret=mat[x][y];
	if(mode){
		ret=max(ret, solve(x, y+1, 1)+mat[x][y]);
		ret=max(ret, solve(x+1, y, 1)+mat[x][y]);
	}
	else{
		ret=max(ret, solve(x, y+1, 0)+mat[x][y]);
		ret=max(ret, solve(x-1, y, 0)+mat[x][y]);
	}
	return ret;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d\n", &n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				char x;
				scanf("%c ", &x);
				mat[i][j]=x=='B';
			}
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(n-1, 0, 0));
	}
	return 0;
}

