// =====================================================================================
// 
//       Filename:  9472.cpp
//        Created:  2017년 08월 11일 23시 29분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cache[1<<17];
int n, k;
ll solve(int idx, int state){
	if(idx==n)
		return 1;
	ll &ret=cache[state];
	if(ret!=-1)
		return ret;
	ret=0;
	if(idx<k){
		for(int i=0;i<n;i++)
			if(i!=idx&&!(state&(1<<i)))
				ret+=solve(idx+1, state|(1<<i));
	}
	else{
		for(int i=0;i<n;i++)
			if(!(state&(1<<i)))
				ret+=solve(idx+1, state|(1<<i));
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		memset(cache, -1, sizeof(cache));
		scanf("%*d%d%d", &n, &k);
		printf("%d %lld\n", tc, solve(0, 0));
	}
	return 0;
}

