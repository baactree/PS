// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 14일 20시 55분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int mod=1e9+7;
int cache[305][1<<18];
int solve(int idx, int state){
	if(idx==n*m)
		return 1;
	int &ret=cache[idx][state];
	if(ret!=-1)
		return ret;
	int y=idx%m;
	ret=solve(idx+1, state>>1);
	if(y==0){
		ret+=solve(idx+1, (state>>1)|(1<<m));
		ret%=mod;
	}
	else if(!(state&1)||!(state&2)||!(state&(1<<m))){
		ret+=solve(idx+1, (state>>1)|(1<<m));
		ret%=mod;
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	if(m>n)
		swap(n, m);
	printf("%d\n", solve(0, 0));
	return 0;
}

