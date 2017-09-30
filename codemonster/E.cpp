// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 29일 13시 31분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<pair<int, pair<int, int> > > adj[1005];
ll dist[1005];
vector<int> edge[20005];
vector<int> to[1005];
vector<bool> chk;
void dijk(int st){
	memset(dist, 0x3f, sizeof(dist));
	dist[st]=0;
	priority_queue<pair<ll, int> > pq;
	pq.push({0, st});
	while(!pq.empty()){
		int now=pq.top().second;
		ll cost=-pq.top().first;
		pq.pop();
		if(dist[now]<cost)
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			ll there_cost=adj[now][i].second.first+cost;
			if(there_cost<dist[there]){
				dist[there]=there_cost;
				pq.push({-there_cost, there});
			}
		}
	}
	for(int i=0;i<1005;i++)
		to[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			int there=adj[i][j].first;
			int weight=adj[i][j].second.first;
			int idx=adj[i][j].second.second;
			if(dist[there]==dist[i]+weight){
				to[there].push_back(idx);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(to[i].empty())
			continue;
		for(int j=0;j<to[i].size();j++)
			edge[to[i][j]].push_back(chk.size());
		chk.push_back(0);
	}
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<1005;i++)
			adj[i].clear();
		for(int i=0;i<20005;i++)
			edge[i].clear();
		chk.clear();
		scanf("%d%d", &n, &m);
		vector<pair<int, int> > vec;
		for(int i=0;i<m;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			adj[a].push_back({b, {d, i}});
			vec.push_back({d, i});
		}
		for(int i=1;i<=n;i++)
			dijk(i);
		sort(vec.begin(), vec.end());
		ll ans=0;
		for(int i=0;i<vec.size();i++){
			int weight=vec[i].first;
			int idx=vec[i].second;
			int cnt=0;
			for(int j=0;j<edge[idx].size();j++){
				if(!chk[edge[idx][j]])
					cnt++;
			}
			if(cnt)
				ans+=weight;
			for(int j=0;j<edge[idx].size();j++)
				chk[edge[idx][j]]=true;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

