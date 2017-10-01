// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 30일 20시 45분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
int main(){
	scanf("%d", &n);
	for(ll i=1;i<=3500;i++)
		for(ll j=1;j<=3500;j++){
			ll now=4*i*j-n*(i+j);
			if(now>0&&(n*i*j)%now==0)
				return !printf("%lld %lld %lld\n", i, j, n*i*j/now);
		}
	return 0;
}

