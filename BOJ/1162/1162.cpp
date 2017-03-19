// =====================================================================================
// 
//       Filename:  1162.cpp
//        Created:  2017년 03월 19일 18시 39분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > adj[10001];
int dist[10001][21];
struct Node{
	int c, v, k;
	bool operator < (const Node& rhs)const{
		return c<rhs.c;
	}
};
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	priority_queue<Node> pq;
	pq.push({0, 1, 0});
	memset(dist, 0x3f, sizeof(dist));
	dist[1][0]=0;
	while(!pq.empty()){
		int now=pq.top().v;
		int cost=-pq.top().c;
		int nk=pq.top().k;
		pq.pop();
		if(dist[now][nk]<cost)
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=adj[now][i].second+cost;
			if(there_cost<dist[there][nk]){
				dist[there][nk]=there_cost;
				pq.push({-there_cost, there, nk});
			}
			if(nk<k){
				if(cost<dist[there][nk+1]){
					dist[there][nk+1]=cost;
					pq.push({-cost, there, nk+1});
				}
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<=k;i++)
		ans=min(ans, dist[n][i]);
	printf("%d\n", ans);
	return 0;
}

