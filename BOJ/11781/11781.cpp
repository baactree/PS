// =====================================================================================
// 
//       Filename:  11781.cpp
//        Created:  2017년 06월 02일 12시 53분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, w, t;
};
int n, m, s, e;
vector<Edge> adj[5005];
long long dist[5005];
long long calc(int mode, long long st, long long dist){
	if(mode){
		if(st<s){
			long long t=s-st;
			if(t>=dist)
				return dist;
			long long p=dist-t;
			if(p*2<=e-s)
				return dist*2-t;
			return dist+(e-s)/2;
		}
		else if(s<=st&&st<e){
			long long t=e-st;
			if(t<dist*2)
				return dist+t/2;
			return dist*2;
		}
		else
			return dist;
	}
	return dist;
}
int main(){
	scanf("%d%d%d%d", &n, &m, &s, &e);
	s*=2;
	e*=2;
	for(int i=0;i<m;i++){
		int a, b, c, d, e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		adj[a].push_back({b, c*2, d});
		adj[b].push_back({a, c*2, e});
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[1]=0;
	priority_queue<pair<long long, int> > pq;
	pq.push({0, 1});
	while(!pq.empty()){
		int now=pq.top().second;
		long long cost=-pq.top().first;
		pq.pop();
		if(cost>dist[now])
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].v;
			long long there_cost=cost+calc(adj[now][i].t, dist[now], adj[now][i].w);
			if(there_cost<dist[there]){
				dist[there]=there_cost;
				pq.push({-there_cost, there});
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans, dist[i]);
	}
	printf("%lld", ans/2);
	if(ans&1)
		printf(".5\n");
	return 0;
}

