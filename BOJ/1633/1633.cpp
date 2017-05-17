// =====================================================================================
// 
//       Filename:  1633.cpp
//        Created:  2017년 05월 15일 01시 28분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, cost, flow, capacity, rev;
	Edge(int v, int cost, int capacity):v(v), cost(cost), capacity(capacity), flow(0), rev(0){}
	int residual(){
		if(flow<0)
			return -flow;
		return capacity-flow;
	}
	int get_cost();
	void push(int amt);
};
vector<Edge> adj[1010];
void make_edge(int u, int v, int cost, int capacity){
	Edge uv=Edge(v, cost, capacity);
	Edge vu=Edge(u, 0, 0);
	uv.rev=adj[v].size();
	vu.rev=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int n;
bool trip[1010];
int dist[1010];
int par[1010];
int f[1010];
int num[1010];
const int inf=0x3f3f3f3f;
int mcmf(int s, int t){
	int totalflow=0;
	int totalcost=0;
	while(true){
		memset(trip, 0, sizeof(trip));
		memset(dist, 0x3f, sizeof(dist));
		memset(par, -1, sizeof(par));
		memset(f, 0x3f, sizeof(f));
		memset(num, 0, sizeof(num));
		queue<int> q;
		q.push(s);
		trip[s]=true;
		dist[s]=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			trip[now]=false;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].v;
				int r=adj[now][i].residual();
				if(r<=0)
					continue;
				int there_cost=dist[now];
				if(adj[now][i].flow<0)
					there_cost+=-adj[there][adj[now][i].rev].cost;
				else
					there_cost+=adj[now][i].cost;
				if(dist[there]>there_cost){
					dist[there]=there_cost;
					par[there]=now;
					num[there]=i;
					f[there]=min(f[now], r);
					if(!trip[there]){
						trip[there]=true;
						q.push(there);
					}
				}
			}
		}
		if(dist[t]==inf)
			break;
		int now=t;
		int amt=f[t];
		totalcost+=amt*dist[t];
		while(now!=s){
			int p=par[now];
			int idx=num[now];
			adj[p][idx].flow+=amt;
			adj[now][adj[p][idx].rev].flow-=amt;
			now=p;
		}
	}
	return totalcost;
}
int main(){
	make_edge(0, 1, 0, 15);
	make_edge(0, 2, 0, 15);
	n=3;
	int b, w;
	while(scanf("%d%d", &w, &b)!=EOF){
		make_edge(1, n, -b, inf);
		make_edge(2, n, -w, inf);
		make_edge(n, 1005, 0, 1);
		n++;
	}
	printf("%d\n", -mcmf(0, 1005));
	return 0;
}

