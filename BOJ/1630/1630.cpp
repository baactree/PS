// =====================================================================================
// 
//       Filename:  1630.cpp
//        Created:  2017년 09월 22일 21시 52분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
bool prime[1000005];
vector<int> p;
typedef long long ll;
const int mod=987654321;
int main(){
	for(int i=2;i<1000005;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i+i;j<1000005;j+=i)
				prime[j]=true;
		}
	}
	scanf("%d", &n);
	ll ans=1;
	for(int i=0;i<p.size()&&p[i]<=n;i++){
		ll r=1;
		while(r*p[i]<=n){
			r*=p[i];
		}
		ans=(ans*r)%mod;
	}
	printf("%lld\n", ans);
	return 0;
}

