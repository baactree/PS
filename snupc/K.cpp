// =====================================================================================
// 
//       Filename:  K.cpp
//        Created:  2017년 09월 14일 22시 43분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main(){
	scanf("%lld", &n);
	ll min_value=0x3f3f3f3f3f3f3f;	
	ll a, b, c;
	ll t=cbrt(n);
	for(ll i=max(1ll, t-2000);i<t+2000;i++)
		for(ll j=max(1ll, t-2000);j<t+2000;j++){
			ll k=(n+i*j-1)/(i*j);
			ll now=(i*j+j*k+k*i)*2;
			if(min_value>now){
				min_value=now;
				a=i;
				b=j;
				c=k;
			}
		}
	printf("%lld %lld %lld\n", a, b, c);
	return 0;
}

