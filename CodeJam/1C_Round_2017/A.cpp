// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 04월 30일 17시 52분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
pair<ll, ll> arr[1001];
ll cache[1001][1001];
ll solve(int idx, int cnt){
	if(idx==n)
		return -0x3f3f3f3f;
	ll &ret=cache[idx][cnt];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, cnt);
	if(cnt+1==k)
		ret=max(ret, arr[idx].second*arr[idx].first*2+arr[idx].first*arr[idx].first);
	else
		ret=max(ret, solve(idx+1, cnt+1)+arr[idx].second*arr[idx].first*2);
	return ret;
}
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d%d", &n, &k);
		for(int i=0;i<n;i++)
			scanf("%lld%lld", &arr[i].first, &arr[i].second);
		sort(arr, arr+n);
		memset(cache, -1, sizeof(cache));
		printf("Case #%d: %.10lf\n",tc, solve(0, 0)*3.14159265359);
	}
	return 0;
}

