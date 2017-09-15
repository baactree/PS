// =====================================================================================
// 
//       Filename:  I.cpp
//        Created:  2017년 09월 15일 01시 56분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
ll arr[200005];
ll dp[200005];
const ll linf=0x3f3f3f3f3f3f3f3f;
int main(){
	scanf("%d%d", &n, &m);
	memset(arr, 0x3f, sizeof(arr));
	vector<pair<ll, ll> > vec;
	for(int i=0;i<m;i++){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		arr[a]=min(arr[a], b);
	}
	ll min_value=linf;
	for(int i=1;i<=n;i++)
		if(arr[i]!=linf){
			vec.push_back({i, arr[i]});
			min_value=min(min_value, arr[i]);
		}
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<vec.size();j++){
			ll now=0;
			if(i-vec[j].first<=0){
				now=vec[j].second;
			}
			else{
				now=dp[i-vec[j].first]+vec[j].second;
			}
			dp[i]=min(dp[i], now);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%lld\n", dp[i]);
	return 0;
}

