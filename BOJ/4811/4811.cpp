// =====================================================================================
// 
//       Filename:  4811.cpp
//        Created:  2017년 03월 08일 22시 27분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long cache[31][31];
long long solve(int w, int h){
	if(w==0&&h==0)
		return 1;
	long long &ret=cache[w][h];
	if(ret!=-1)
		return ret;
	ret=0;
	if(w!=0)
		ret+=solve(w-1, h+1);
	if(h!=0)
		ret+=solve(w, h-1);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		printf("%lld\n", solve(n, 0));
	}
	return 0;
}

