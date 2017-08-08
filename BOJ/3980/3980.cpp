// =====================================================================================
// 
//       Filename:  3980.cpp
//        Created:  2017년 08월 08일 12시 53분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
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
vector<Edge> adj[30];
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
int dist[30];
int idx[30];
int amount[30];
int par[30];
int trip[30];
int flow(int s, int t){
	int ret=0;
	while(true){
		memset(dist, 0x3f, sizeof(dist));
		memset(trip, 0, sizeof(trip));
		amount[s]=inf;
		trip[s]=true;
		queue<int> q;
		q.push(s);
		dist[s]=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			trip[now]=false;
			for(int i=0;i<adj[now].size();i++){
				int there=adj[now][i].v;
				int r=adj[now][i].residual();
				if(r>0){
					int w=adj[now][i].get_cost();
					if(dist[now]+w<dist[there]){
						dist[there]=dist[now]+w;
						par[there]=now;
						amount[there]=min(amount[now], r);
						idx[there]=i;
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
			adj[p][idx[now]].push(amount[t]);
			now=p;
		}
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<30;i++)
			adj[i].clear();
		int s=0;
		int t=23;
		for(int i=1;i<=11;i++){
			make_edge(s, i, 1, 0);
			make_edge(i+11, t, 1, 0);
			for(int j=1;j<=11;j++){
				int x;
				scanf("%d", &x);
				if(x!=0)
					make_edge(i, j+11, 1, -x);
			}
		}
		printf("%d\n", -flow(s, t));
	}
	return 0;
}

