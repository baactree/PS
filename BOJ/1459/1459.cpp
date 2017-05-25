// =====================================================================================
// 
//       Filename:  1459.cpp
//        Created:  2017년 05월 24일 16시 19분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long x, y, s, w;
int main(){
	scanf("%lld%lld%lld%lld", &x, &y, &w, &s);
	if(2*w<s)
		printf("%lld\n", (x+y)*w);
	else{
		if(x>y)
			swap(x, y);
		if(2*s<2*w){
			long long a=(y-x)/2;
			long long b=(y-x)&1;
			printf("%lld\n", x*s+2*a*s+b*w);
		}
		else
			printf("%lld\n", x*s+(y-x)*w);
	}
	return 0;
}

