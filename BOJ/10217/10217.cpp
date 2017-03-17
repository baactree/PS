// =====================================================================================
// 
//       Filename:  10217.cpp
//        Created:  2017년 03월 17일 19시 18분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct Edge{
	int v, x, d;
};
struct Node{
	int c, v, m;
	bool operator < (const Node& rhs)const{
		return c<rhs.c;
	}
};
vector<Edge> adj[101];
int dist[101][10001];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		for(int i=0;i<101;i++)
			adj[i].clear();
		memset(dist, 0x3f, sizeof(dist));
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0;i<k;i++){
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			adj[a].push_back({b, c, d});
		}
		dist[1][0]=0;
		priority_queue<Node> pq;
		pq.push({0, 1, 0});
		while(!pq.empty()){
			int now=pq.top().v;
			int cost=-pq.top().c;
			int money=pq.top().m;
			pq.pop();
			if(cost>dist[now][money])
				continue;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].v;
				int there_cost=cost+adj[now][i].d;
				int there_money=money+adj[now][i].x;
				if(there_money>m)
					continue;
				if(there_cost<dist[there][there_money]){
					dist[there][there_money]=there_cost;
					pq.push({-there_cost, there, there_money});
				}
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=m;i++)
			ans=min(ans, dist[n][i]);
		if(ans==0x3f3f3f3f)
			printf("Poor KCM\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}

