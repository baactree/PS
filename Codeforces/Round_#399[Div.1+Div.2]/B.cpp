// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 02월 21일 01시 11분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n, l, r;
long long solve(long long x, long long n){
	if(x==0)
		return 0;
	int s=0;
	long long t=n;
	long long len=1;
	while(t>1){
		len=len*2+1;
		t>>=1;
	}
	if(len/2>x-1)
		return solve(x, n/2);
	if(len/2==x-1)
		return n/2+n%2;
	return solve(x-len/2-1, n/2)+n%2+n/2;
}
int main(){
	scanf("%lld%lld%lld", &n, &l, &r);
	printf("%lld\n", solve(r, n)-solve(l-1, n));
	return 0;
}

