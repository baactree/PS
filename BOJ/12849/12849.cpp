// =====================================================================================
// 
//       Filename:  12849.cpp
//        Created:  2017년 06월 10일 14시 08분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int d;
int mat[8][8]={
	{0, 1, 1, 0, 0, 0, 0, 0}, 
	{1, 0, 1, 1, 0, 0, 0, 0}, 
	{1, 1, 0, 1, 1, 0, 0, 0}, 
	{0, 1, 1, 0, 1, 1, 0, 0}, 
	{0, 0, 1, 1, 0, 1, 1, 0}, 
	{0, 0, 0, 1, 1, 0, 0, 1}, 
	{0, 0, 0, 0, 1, 0, 0, 1}, 
	{0, 0, 0, 0, 0, 1, 1, 0}
};
int cache[8][8][100005];
int solve(int u, int v, int k){
	if(k==0)
		return u==v;
	int &ret=cache[u][v][k];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<8;i++)
		if(mat[u][i]){
			ret+=solve(i, v, k-1);
			ret%=mod;
		}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &d);
	printf("%d\n", solve(0, 0, d));
	return 0;
}

