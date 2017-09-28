// =====================================================================================
// 
//       Filename:  12011.cpp
//        Created:  2017년 09월 29일 01시 35분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
const int inf=0x3f3f3f3f;
typedef long long ll;
pair<ll, ll> arr[50005];
const ll linf=0x3f3f3f3f3f3f3f3f;
ll calc(){
	map<ll, int> ri, le;
	for(int i=0;i<n;i++)
		ri[arr[i].second]++;
	ll lx, rx;
	lx=arr[0].first;
	rx=arr[n-1].first;
	ll ret=(rx-lx)*((--ri.end())->first-(ri.begin())->first);
	for(int i=0;i+1<n;i++){
		ri[arr[i].second]--;
		if(ri[arr[i].second]==0)
			ri.erase(arr[i].second);
		le[arr[i].second]++;
		if(arr[i].first==arr[i+1].first)
			continue;
		ll now=(arr[i].first-lx)*((--le.end())->first-(le.begin())->first);
		now+=(rx-arr[i+1].first)*((--ri.end())->first-(ri.begin())->first);
		ret=min(ret, now);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	ll minx, miny, maxx, maxy;
	minx=miny=inf;
	maxx=maxy=0;
	for(int i=0;i<n;i++){
		scanf("%lld%lld", &arr[i].first, &arr[i].second);
		minx=min(minx, (ll)arr[i].first);
		maxx=max(maxx, (ll)arr[i].first);
		miny=min(miny, (ll)arr[i].second);
		maxy=max(maxy, (ll)arr[i].second);
	}
	sort(arr, arr+n);
	ll ans=calc();
	for(int i=0;i<n;i++)
		swap(arr[i].first, arr[i].second);
	sort(arr, arr+n);
	ans=min(ans, calc());
	printf("%lld\n", (maxx-minx)*(maxy-miny)-ans);
	return 0;
}

