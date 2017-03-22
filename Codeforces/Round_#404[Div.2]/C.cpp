// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 03월 21일 20시 11분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
bool possi(ll x){
	if(x<=m)
		return n-x<=0;
	x-=m;
	return (n-m)<=x*(x+1)/2;
}
int main(){
	scanf("%lld%lld", &n, &m);
	if(n<=m){
		printf("%lld\n", n);
		return 0;
	}
	ll le, ri, mid, ans;
	le=1;ri=n;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}

