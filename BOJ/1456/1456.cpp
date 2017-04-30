// =====================================================================================
// 
//       Filename:  1456.cpp
//        Created:  2017년 04월 30일 21시 08분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
bool prime[10000000];
vector<ll> p;
int main(){
	scanf("%lld%lld", &a, &b);
	long long ans=0;
	for(int i=2;i<1e7;i++){
		if(prime[i])
			continue;
		p.push_back(i);
		prime[i]=true;
		for(int j=i+i;j<1e7;j+=i)
			prime[j]=true;
	}
	for(int i=0;i<p.size();i++){
		ll now=p[i]*p[i];
		while(now<=b){
			if(a<=now)
				ans++;
			if(now>b/p[i])
				break;
			now*=p[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}

