// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 14일 19시 04분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[65];
const int mod=1e9+7;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		priority_queue<ll> pq;
		for(int i=0;i<n;i++){
			scanf("%lld", &arr[i]);
			pq.push(-arr[i]);
		}
		ll ans=1;
		for(int i=0;i<n-1;i++){
			ll a=-pq.top();
			pq.pop();
			ll b=-pq.top();
			pq.pop();
			ans=(ans*((a*b)%mod))%mod;
			pq.push(-a*b);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

