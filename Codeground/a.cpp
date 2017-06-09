// =====================================================================================
// 
//       Filename:  a.cpp
//        Created:  2017년 06월 08일 17시 44분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
const ll linf=0x3f3f3f3f3f3f3f3f;
vector<vector<pair<int, int> > > adj;
vector<vector<pair<int, int> > > padj;
vector<vector<pair<int, int> > > qadj;
vector<ll> pdist;
vector<ll> qdist;
vector<ll> dist;
vector<bool> trip;
void dfs(int now){
	trip[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int cnt=0;
		if(pdist[there]!=pdist[now]+padj[now][i].second)
			cnt++;
		if(qdist[there]!=qdist[now]+qadj[now][i].second)
			cnt++;
		adj[now][i].second=cnt;
		if(!trip[there])
			dfs(there);
	}
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d%d", &n, &m);
		adj=padj=qadj=vector<vector<pair<int, int> > >(n+5);
		dist=pdist=qdist=vector<ll>(n+5, linf);
		trip=vector<bool>(n+5, false);
		for(int i=0;i<m;i++){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			adj[b].push_back({a, 0});
			padj[b].push_back({a, c});
			qadj[b].push_back({a, d});
		}
		priority_queue<pair<ll, int> > pq;
		pdist[n]=0;
		pq.push({0, n});
		while(!pq.empty()){
			int now=pq.top().second;
			ll cost=-pq.top().first;
			pq.pop();
			if(cost>pdist[now])
				continue;
			for(int i=0;i<padj[now].size();i++){
				int there=padj[now][i].first;
				ll there_cost=padj[now][i].second+cost;
				if(pdist[there]>there_cost){
					pdist[there]=there_cost;
					pq.push({-there_cost, there});
				}
			}
		}
		qdist[n]=0;
		pq.push({0, n});
		while(!pq.empty()){
			int now=pq.top().second;
			ll cost=-pq.top().first;
			pq.pop();
			if(cost>qdist[now])
				continue;
			for(int i=0;i<qadj[now].size();i++){
				int there=qadj[now][i].first;
				ll there_cost=qadj[now][i].second+cost;
				if(qdist[there]>there_cost){
					qdist[there]=there_cost;
					pq.push({-there_cost, there});
				}
			}
		}
		dfs(n);
		dist[n]=0;
		pq.push({0, n});
		while(!pq.empty()){
			int now=pq.top().second;
			ll cost=-pq.top().first;
			pq.pop();
			if(cost>dist[now])
				continue;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].first;
				ll there_cost=adj[now][i].second+cost;
				if(dist[there]>there_cost){
					dist[there]=there_cost;
					pq.push({-there_cost, there});
				}
			}
		}
		printf("#testcase%d\n%lld\n", tc, dist[1]);
	}
	return 0;
}

