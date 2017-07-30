// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 07월 30일 23시 20분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
map<ll, int> mp;
int main(){
	scanf("%d", &n);
	for(ll i=1;i<=1e6;i++)
		mp[i*i*i]=i;
	while(n--){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if(mp.count(a*b)!=0){
			ll p=mp[a*b];
			if(a%p==0&&b%p==0){
				printf("Yes\n");
				continue;
			}
		}
		printf("No\n");
	}
	return 0;
}

