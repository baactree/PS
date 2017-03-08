// =====================================================================================
// 
//       Filename:  13699.cpp
//        Created:  2017년 03월 08일 22시 18분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long cache[40];
long long solve(int x){
	if(x==0)
		return 1;
	long long &ret=cache[x];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<x;i++)
		ret+=solve(i)*solve(x-i-1);
	return ret;
}
int n;
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	printf("%lld\n", solve(n));
	return 0;
}

