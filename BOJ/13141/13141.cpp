// =====================================================================================
// 
//       Filename:  13141.cpp
//        Created:  2017년 08월 08일 13시 40분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[205];
int dist[205];
void dijk(int st){
	memset(dist, 0x3f, sizeof(dist));
	dist[st]=0;
	priority_queue<pair<int, int> > pq;
	pq.push({0, st});
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(cost>dist[now])
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=adj[now][i].second+cost;
			if(there_cost<dist[there]){
				dist[there]=there_cost;
				pq.push({-there_cost, there});
			}
		}
	}
}
int calc(int u, int v, int w){
	if(dist[u]>dist[v])
		swap(u, v);
	if(dist[u]+w>dist[v]){
		int k=dist[v]-dist[u];
		return dist[u]+k+(w-k)/2;
	}
	return dist[u]+w;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d*2});
		adj[b].push_back({a, d*2});
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		dijk(i);
		int t=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<adj[j].size();k++){
				int there=adj[j][k].first;
				int w=adj[j][k].second;
				t=max(t, calc(j, there, w));
			}
		}
		ans=min(ans, t);
	}
	printf("%d", ans/2);
	if(ans&1)
		printf(".5\n");
	else
		printf(".0\n");
	return 0;
}

