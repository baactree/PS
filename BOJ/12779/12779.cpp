// =====================================================================================
// 
//       Filename:  12779.cpp
//        Created:  2017년 03월 11일 19시 46분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, p, q;
ll gcd(ll a, ll b){
	return b?gcd(b, a%b):a;
}
int main(){
	scanf("%lld%lld", &a, &b);
	ll p=b-a;
	ll q=(int)sqrt(b)-(int)ceil(sqrt(a+1))+1;
	ll g=gcd(p, q);
	if(q==0)
		printf("0\n");
	else
		printf("%lld/%lld\n", q/g, p/g);
	return 0;
}

