// =====================================================================================
// 
//       Filename:  11408.cpp
//        Created:  2017년 04월 02일 21시 36분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, cost, capacity, flow;
	Edge *rev;
	Edge(){};
	Edge(int v, int cost, int capacity):v(v), cost(cost), capacity(capacity), flow(0), rev(0){}
	int residual(){
		return capacity-flow;
	}
	void push(int amount){
		flow+=amount;
		rev->flow-=amount;
	}
	int getCost(){
		if(flow<0)
			return -cost;
		return cost;
	}
};
vector<Edge*> adj[900];
void make_edge(int u, int v, int capacity, int cost){
	Edge *uv=new Edge(v, cost, capacity);
	Edge *vu=new Edge(u, cost, 0);
	uv->rev=vu;
	vu->rev=uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int n, m;
int dist[900];
int par[900];
int num[900];
int trip[900];
pair<int, int> mcmf(int s, int t){
	pair<int, int> ret={0, 0};
	while(true){
		memset(dist, 0x3f, sizeof(dist));
		memset(par, -1, sizeof(par));
		memset(num, -1, sizeof(num));
		memset(trip, 0, sizeof(trip));
		dist[s]=0;
		queue<int> q;
		q.push(s);
		trip[s]=true;
		int min_flow=0x3f3f3f3f;
		while(!q.empty()){
			int now=q.front();
			trip[now]=false;
			q.pop();
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i]->v;
				int sub=adj[now][i]->residual();
				if(sub<=0)
					continue;
				int there_cost=dist[now]+adj[now][i]->getCost();
				if(there_cost<dist[there]){
					dist[there]=there_cost;
					if(!trip[there]){
						q.push(there);
						trip[there]=true;
					}
					par[there]=now;
					num[there]=i;
					min_flow=min(min_flow, sub);
				}
			}
		}
		if(dist[t]==0x3f3f3f3f)
			break;
		int now=t;
		while(par[now]!=-1){
			int p=par[now];
			int pidx=num[now];
			adj[p][pidx]->push(min_flow);
			now=par[now];
		}
		ret.first+=min_flow;
		ret.second+=min_flow*dist[t];
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		int cnt;
		scanf("%d", &cnt);
		for(int j=0;j<cnt;j++){
			int a, b;
			scanf("%d%d", &a, &b);
			make_edge(i, a+n, 1, b);
		}
	}
	for(int i=1;i<=n;i++)
		make_edge(0, i, 1, 0);
	for(int i=1;i<=m;i++)
		make_edge(i+n, n+m+1, 1, 0);
	pair<int, int> ans=mcmf(0, n+m+1);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}

