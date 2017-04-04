// =====================================================================================
// 
//       Filename:  11564.cpp
//        Created:  2017년 04월 04일 17시 33분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll k, a, b;
	scanf("%lld%lld%lld", &k, &a, &b);
	if(a%k==0&&b%k==0){
		printf("%lld\n", (b-a)/k+1);
	}
	else if(a%k==0&&b%k!=0){
		printf("%lld\n", (b-a)/k+1);
	}
	else if(a%k!=0&&b%k==0){
		printf("%lld\n", (b-a)/k+1);
	}
	else{
		ll ta=a/k*k;
		if(a>0)
			ta+=k;
		ll tb=b/k*k;
		if(b<0)
			tb-=k;
		if(tb<ta){
			printf("0\n");
		}
		else
			printf("%lld\n", (tb-ta)/k+1);
	}
	return 0;

}

