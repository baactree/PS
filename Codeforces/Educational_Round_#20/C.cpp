// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 04월 29일 00시 20분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
int main(){
	scanf("%lld%lld", &n, &k);
	if(k>1e6){
		printf("-1\n");
		return 0;
	}
	ll l=(k*(k+1))/2;
	if(n<l){
		printf("-1\n");
		return 0;
	}
	vector<ll> p;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			p.push_back(i);
			if(i!=n/i)
				p.push_back(n/i);
		}
	}
	sort(p.begin(), p.end());
	int idx=lower_bound(p.begin(), p.end(), l)-p.begin();
	ll q=p[idx];
	ll t=n/q;
	ll s=q-l;
	for(ll i=1;i<k;i++)
		printf("%lld ", (i)*t);
	printf("%lld\n", (s+k)*t);
	return 0;
}

