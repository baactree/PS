// =====================================================================================
// 
//       Filename:  1848.cpp
//        Created:  2017년 08월 08일 13시 53분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[5005];
int dist[5005];
bool perm[5005];
int dijk(int mode){
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int, int> > pq;
	dist[1]=0;
	pq.push({0, 1});
	int ret=0x3f3f3f3f;
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[now]<cost)
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=adj[now][i].second+cost;
			if(now==1&&perm[there]==mode&&dist[there]>there_cost){
				dist[there]=there_cost;
				pq.push({-there_cost, there});
			}
			else if(there==1&&perm[now]==1-mode){
				ret=min(ret, there_cost);
			}
			else if(now!=1&&there!=1&&dist[there]>there_cost){
				dist[there]=there_cost;
				pq.push({-there_cost, there});
			}
		}
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		adj[a].push_back({b, c});
		adj[b].push_back({a, d});
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<13;i++){
		memset(perm, 0, sizeof(perm));
		for(int j=2;j<=n;j++)
			if(j&(1<<i))
				perm[j]=true;
		ans=min(ans, dijk(1));
		ans=min(ans, dijk(0));
	}
	printf("%d\n", ans);
	return 0;
}

