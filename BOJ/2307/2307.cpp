// =====================================================================================
// 
//       Filename:  2307.cpp
//        Created:  2017년 05월 12일 14시 36분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node{
	int v, w, idx;
};
vector<Node> adj[1001];
const int inf=0x3f3f3f3f;
int dist[1001];
int solve(int x){
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<pair<int, int> > pq;
	dist[1]=0;
	pq.push({0, 1});
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(cost>dist[now])
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].v;
			int there_cost=adj[now][i].w+cost;
			int edgeidx=adj[now][i].idx;
			if(edgeidx==x)
				continue;
			if(there_cost<dist[there]){
				dist[there]=there_cost;
				pq.push({-there_cost, there});
			}
		}
	}
	return dist[n];
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d, i});
		adj[b].push_back({a, d, i});
	}
	int d=solve(-1);
	int ans=0;
	for(int i=0;i<m;i++)
		ans=max(ans, solve(i));
	printf("%d\n", ans==inf?-1:ans-d);
	return 0;
}

