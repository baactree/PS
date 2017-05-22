// =====================================================================================
// 
//       Filename:  3640.cpp
//        Created:  2017년 05월 22일 20시 24분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, capacity, flow, cost, rev;
	Edge(){}
	Edge(int v, int capacity, int cost):v(v), capacity(capacity), cost(cost), flow(0), rev(0){}
	int residual(){
		if(flow<0)
			return -flow;
		return capacity-flow;
	}
	int get_cost();
	void push(int amt);
};
vector<Edge> adj[2005];
int Edge::get_cost(){
	if(flow<0)
		return -adj[v][rev].cost;
	return cost;
}
void Edge::push(int amt){
	flow+=amt;
	adj[v][rev].flow-=amt;
}
void make_edge(int u, int v, int capacity, int cost){
	Edge uv=Edge(v, capacity, cost);
	Edge vu=Edge(u, 0, 0);
	uv.rev=adj[v].size();
	vu.rev=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int v, e;
int dist[2005];
int par[2005];
int idx[2005];
int amt[2005];
bool trip[2005];
const int inf=0x3f3f3f3f;
int flow(int s, int t){
	int ret=0;
	while(true)	{
		memset(dist, 0x3f, sizeof(dist));
		memset(trip, 0, sizeof(trip));
		dist[s]=0;
		trip[s]=true;
		amt[s]=inf;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			trip[now]=false;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].v;
				if(adj[now][i].residual()>0){
					int cost=adj[now][i].get_cost();
					if(dist[there]>dist[now]+cost){
						dist[there]=dist[now]+cost;
						par[there]=now;
						idx[there]=i;
						amt[there]=min(amt[now], adj[now][i].residual());
						if(!trip[there]){
							trip[there]=true;
							q.push(there);
						}
					}
				}
			}
		}
		if(dist[t]==inf)
			break;
		ret+=dist[t]*amt[t];
		int now=t;
		while(now!=s){
			int p=par[now];
			adj[p][idx[now]].push(amt[t]);
			now=par[now];
		}
	}
	return ret;
}
int main(){
	while(scanf("%d%d", &v, &e)!=EOF){
		for(int i=0;i<2005;i++)
			adj[i].clear();
		for(int i=0;i<e;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			make_edge(a*2+1, b*2, 1, d);
		}
		for(int i=1;i<=v;i++){
			if(i==1||i==v)
				make_edge(i*2, i*2+1, inf, 0);
			else
				make_edge(i*2, i*2+1, 1, 0);
		}
		int s, t;
		s=0;
		t=1;
		make_edge(s, 2, 2, 0);
		make_edge(v*2+1, 1, 2, 0);
		printf("%d\n", flow(s, t));
	}
	return 0;
}

