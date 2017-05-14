// =====================================================================================
// 
//       Filename:  14494.cpp
//        Created:  2017년 05월 14일 17시 28분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int cache[1000][1000];
const int mod=1e9+7;
int solve(int x, int y){
	if(x==n-1&&y==m-1)
		return 1;
	int &ret=cache[x][y];
	if(ret!=-1)
		return ret;
	ret=0;
	if(x!=n-1){
		ret+=solve(x+1, y);
		ret%=mod;
	}
	if(y!=m-1){
		ret+=solve(x, y+1);
		ret%=mod;
	}
	if(x!=n-1&&y!=m-1){
		ret+=solve(x+1, y+1);
		ret%=mod;
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	printf("%d\n", solve(0, 0));
	return 0;
}

