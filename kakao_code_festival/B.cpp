// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 08월 05일 13시 12분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mod = 20170805;
int n, m;
vector<vector<int> > mat;
int cache[505][505][2];
int dx[2]={1, 0};
int dy[2]={0, 1};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solve(int x, int y, int mode){

	if(x==n||y==m)
		return 0;
	if(x==n-1&&y==m-1)
		return 1;
	int &ret=cache[x][y][mode];
	if(ret!=-1)
		return ret;
	ret=0;
	if(mat[x][y]==0)
		for(int i=0;i<2;i++){
			ret+=solve(x+dx[i], y+dy[i], i);
			ret%=mod;
		}
	else if(mat[x][y]==2){
		ret+=solve(x+dx[mode], y+dy[mode], mode);
		ret%=mod;
	}
	return ret;
}
int solution(int N, int M, vector<vector<int>> city_map) {
	n=N;
	m=M;
	mat=city_map;
	memset(cache, -1, sizeof(cache));
    return solve(0, 0, 0);
}

