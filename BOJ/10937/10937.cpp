// =====================================================================================
// 
//       Filename:  10937.cpp
//        Created:  2017년 05월 22일 19시 29분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, capacity, flow, rev, cost;
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
vector<Edge> adj[200];
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
char mat[13][13];
int n;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int g[300][300];
bool safe(int x, int y){
	return min(x, y)>=0&&max(x, y)<n;
}
int par[200];
int num[200];
int dist[200];
int trip[200];
int amount[200];
const int inf=0x3f3f3f3f;
int flow(int s, int t){
	int ret=0;
	while(true){
		memset(dist, 0x3f, sizeof(dist));
		memset(par, -1, sizeof(par));
		memset(trip, 0, sizeof(trip));
		memset(num, -1, sizeof(num));
		memset(amount, 0x3f, sizeof(amount));
		queue<int> q;
		q.push(s);
		dist[s]=0;
		trip[s]=true;
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
						amount[there]=min(amount[now], adj[now][i].residual());
						par[there]=now;
						num[there]=i;
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
		ret+=amount[t]*dist[t];
		int now=t;
		while(now!=s){
			int p=par[now];
			adj[p][num[now]].push(amount[t]);
			now=par[now];
		}
	}
	return -ret;
}
int main(){
	g['A']['A']=100;
	g['A']['B']=70;
	g['A']['C']=40;
	g['B']['A']=70;
	g['B']['B']=50;
	g['B']['C']=30;
	g['C']['A']=40;
	g['C']['B']=30;
	g['C']['C']=20;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	int s, t;
	s=n*n;
	t=n*n+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if((i+j)&1){
				make_edge(s, i*n+j, 1, 0);
				make_edge(i*n+j, t, 1, 0);
				for(int k=0;k<4;k++){
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(safe(nx, ny)){
						int cost=g[mat[i][j]][mat[nx][ny]];
						make_edge(i*n+j, nx*n+ny, 1, -cost);
					}
				}
			}
			else{
				make_edge(i*n+j, t, 1, 0);
			}
		}
	printf("%d\n", flow(s, t));
	return 0;
}

