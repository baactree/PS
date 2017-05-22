// =====================================================================================
// 
//       Filename:  1407.cpp
//        Created:  2017년 05월 22일 16시 31분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x){
	ll ret=0;
	ll r=1;
	while(true){
		ll k=x/r;
		if(k==0)
			break;
		ret-=k*(r/2);
		ret+=k*r;
		r*=2;
	}
	return ret;
}
ll a, b;
int main(){
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", f(b)-f(a-1));
	return 0;
}

