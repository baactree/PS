// =====================================================================================
// 
//       Filename:  1500.cpp
//        Created:  2017년 03월 21일 18시 54분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int s, k;
	scanf("%d%d", &s, &k);
	int t=s%k;
	long long ans=1;
	int i;
	for(i=0;i<t;i++)
		ans*=(s/k+1);
	for(;i<k;i++)
		ans*=s/k;
	printf("%lld\n", ans);
	return 0;
}

