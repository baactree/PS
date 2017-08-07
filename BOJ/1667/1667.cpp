// =====================================================================================
// 
//       Filename:  1667.cpp
//        Created:  2017년 08월 05일 12시 18분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, s;
map<int, ll> mp;
const int inf=0x3f3f3f3f3f3f3f3f;
int main(){
	scanf("%d%d", &n, &s);
	mp[s]=0;
	for(int i=0;i<n;i++){
		ll l, h;
		scanf("%lld%lld", &l, &h);
		auto lit=mp.lower_bound(l);
		auto hit=mp.upper_bound(h);
		ll lmin, hmin;
		lmin=hmin=inf;
		for(auto it=lit;it!=hit;it++){
			lmin=min(lmin, it->first-l+it->second);
			hmin=min(hmin, h-it->first+it->second);
		}
		mp.erase(lit, hit);
		mp[l]=lmin;
		mp[h]=hmin;
	}
	ll ans=inf;
	for(auto it=mp.begin();it!=mp.end();it++)
		ans=min(ans, abs(it->first)+it->second);
	printf("%lld\n", ans);
	return 0;
}

