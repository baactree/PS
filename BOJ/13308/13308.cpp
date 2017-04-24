// =====================================================================================
// 
//       Filename:  13308.cpp
//        Created:  2017년 04월 24일 23시 11분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<pair<int, int> > adj[2505];
ll dist[2505][2505];
int arr[2505];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<ll, pair<int, int> > > pq;
	pq.push({0, {1, 2504}});
	dist[1][2504]=0;
	while(!pq.empty()){
		int now=pq.top().second.first;
		int pre=pq.top().second.second;
		ll cost=-pq.top().first;
		pq.pop();
		if(cost>dist[now][pre])
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int next=min(pre, arr[now]);
			ll there_cost=cost+adj[now][i].second*next;
			if(dist[there][next]>there_cost){
				dist[there][next]=there_cost;
				pq.push({-there_cost, {there, next}});
			}
		}
	}
	ll ans=0x3f3f3f3f3f3f3f3f3f;
	for(int i=0;i<2505;i++)
		ans=min(ans, dist[n][i]);
	printf("%lld\n", ans);
	return 0;
}

