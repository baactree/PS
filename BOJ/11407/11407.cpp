// =====================================================================================
// 
//       Filename:  11407.cpp
//        Created:  2017년 08월 29일 00시 13분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, c, f, w, r;
	Edge(){}
	Edge(int v, int c, int w):v(v), c(c), w(w), f(0), r(0){}
	int residual(){
		if(f<0)
			return -f;
		return c-f;
	}
	int get_cost();
	void push(int amt);
};
vector<Edge> adj[300];
int Edge::get_cost(){
	if(f<0)
		return -adj[v][r].w;
	return w;
}
void Edge::push(int amt){
	f+=amt;
	adj[v][r].f-=amt;
}
void make_edge(int u, int v, int c, int w){
	Edge uv(v, c, w);
	Edge vu(u, 0, 0);
	uv.r=adj[v].size();
	vu.r=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int dist[300], par[300], idx[300], amt[300], trip[300];
const int inf=0x3f3f3f3f;
pair<int, int> flow(int s, int t){
	pair<int, int> ret={0, 0};
	while(true){
		memset(dist, 0x3f, sizeof(dist));
		queue<int> q;
		q.push(s);
		dist[s]=0;
		amt[s]=inf;
		trip[s]=true;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			trip[now]=false;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].v;
				int r=adj[now][i].residual();
				int w=adj[now][i].get_cost();
				if(r>0&&dist[there]>dist[now]+w){
					dist[there]=dist[now]+w;
					par[there]=now;
					idx[there]=i;
					amt[there]=min(amt[now], r);
					if(!trip[there]){
						trip[there]=true;
						q.push(there);
					}
				}
			}
		}
		if(dist[t]==inf)
			break;
		ret.first+=amt[t];
		ret.second+=dist[t]*amt[t];
		int now=t;
		while(now!=s){
			int p=par[now];
			adj[p][idx[now]].push(amt[t]);
			now=p;
		}
	}
	return ret;
}
int n, m;
int c[105][105];
int w[105][105];
int main(){
	scanf("%d%d", &n, &m);
	int s=0;
	int t=n+m+1;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		make_edge(m+i, t, x, 0);
	}
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d", &x);
		make_edge(s, i, x, 0);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &c[i][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &w[i][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			make_edge(i, j+m, c[i][j], w[i][j]);
	auto ans=flow(s, t);
	printf("%d\n%d\n", ans.first, ans.second);
	return 0;
}

