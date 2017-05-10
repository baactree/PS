// =====================================================================================
// 
//       Filename:  10978.cpp
//        Created:  2017년 04월 28일 15시 48분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long cache[1<<20];
long long solve(int idx, int state){
	if(idx==n)
		return 1;
	long long &ret=cache[state];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<n;i++){
		if(i==idx)
			continue;
		if((1<<i)&state)
			continue;
		ret+=solve(idx+1, state|(1<<i));
	}
	return ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		printf("%lld\n", solve(0, 0));
	}
	return 0;
}

