// =====================================================================================
// 
//       Filename:  1044.cpp
//        Created:  2017년 05월 02일 12시 28분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> mp;
int n;
ll a[36];
ll b[36];
ll ans;
ll min_value=0x3f3f3f3f3f3f3f3f;
void solve(int idx, ll diff, ll state){
	if(idx==n/2){
		if(mp.count(diff)==0)
			mp[diff]=state;
		return;
	}
	solve(idx+1, diff+a[idx], state);
	solve(idx+1, diff-b[idx], state|(1ll<<idx));
}
void solve2(int idx, ll diff, ll state){
	if(idx==n){
		auto it = mp.lower_bound(-diff);
		if(it!=mp.end()){
			ll f=it->first;
			ll s=it->second;
			if(abs(f+diff)<min_value){
				min_value=abs(f+diff);
				ans=state+s;
			}
			else if(abs(f+diff)==min_value){
				ll temp=state+s;
				if(ans>temp)
					ans=temp;
			}
		}
		if(it!=mp.begin()){
			it--;
			ll f=it->first;
			ll s=it->second;
			if(abs(f+diff)<min_value){
				min_value=abs(f+diff);
				ans=state+s;
			}
			else if(abs(f+diff)==min_value){
				ll temp=state+s;
				if(ans>temp)
					ans=temp;
			}
		}
		return;
	}
	solve2(idx+1, diff+a[idx], state);
	solve2(idx+1, diff-b[idx], state|(1ll<<idx));
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &a[i]);
	for(int i=0;i<n;i++)
		scanf("%lld", &b[i]);
	solve(0, 0, 0);
	solve2(n/2, 0, 0);
	for(int i=0;i<n;i++)
		if(ans&(1ll<<i))
			printf("2 ");
		else
			printf("1 ");
	return 0;
}

