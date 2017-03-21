// =====================================================================================
// 
//       Filename:  13241.cpp
//        Created:  2017년 03월 21일 18시 05분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	return b?gcd(b, a%b):a;
}
int main(){
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll g = gcd(a, b);
	printf("%lld\n", a/g*b);
	return 0;
}

