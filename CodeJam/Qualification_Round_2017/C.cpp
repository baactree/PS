// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 04월 08일 14시 28분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for(int t=1;t<=tc;t++){
		ll k, n;
		scanf("%lld%lld", &n, &k);
		map<ll, ll> m;
		queue<ll> q;
		q.push(n);
		m[n]=1;
		vector<ll> arr;
		arr.push_back(n);
		while(!q.empty()){
			ll now=q.front();
			q.pop();
			if(now<=1)
				continue;
			if(now&1){
				ll there=now/2;
				if(m.count(there)==0){
					arr.push_back(there);
					q.push(there);
				}
				m[there]+=m[now]*2;
			}
			else{
				ll there_a=now/2;
				ll there_b=now/2-1;
				if(m.count(there_a)==0){
					arr.push_back(there_a);
					q.push(there_a);
				}
				if(m.count(there_b)==0){
					arr.push_back(there_b);
					q.push(there_b);
				}
				m[there_a]+=m[now];
				m[there_b]+=m[now];
			}
		}
		sort(arr.begin(), arr.end());
		ll ans;
		for(int i=arr.size()-1;i>=0;i--){
			k-=m[arr[i]];
			if(k<=0){
				ans=arr[i];
				break;
			}
		}
		if(ans&1)
			printf("Case #%d: %lld %lld\n", t, ans/2, ans/2);
		else
			printf("Case #%d: %lld %lld\n", t, ans/2, ans/2-1);
	}
	return 0;
}

