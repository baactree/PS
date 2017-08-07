// =====================================================================================
// 
//       Filename:  9527.cpp
//        Created:  2017년 08월 04일 23시 24분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
/*
 * 00000
 * 00001
 * 00010
 * 00011
 * 00100
 * 00101
 * 00110
 * 00111
 * 01000
 * 01001
 * 01010
 * 01011
 * 01100
 *
 */
ll solve(ll x){
	ll ret=0;
	for(int i=0;i<60;i++){
		//i번째 비트에 대해서 (1<<(i+1))의 주기를 가지고 
		//1<<i번 켜지고 1<<i번 꺼져있다.
		ll t=(x+1)/(1ll<<(i+1))*(1ll<<i);
		ll p=max(0ll, (x+1)%(1ll<<(i+1))-(1ll<<i));
		ret+=t+p;
	}
	return ret;
}
int main(){
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", solve(b)-solve(a-1));
	return 0;
}

