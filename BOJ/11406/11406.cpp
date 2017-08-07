// =====================================================================================
// 
//       Filename:  11406.cpp
//        Created:  2017년 08월 03일 14시 11분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, c, f, r;
	Edge(){}
	Edge(int v, int c):v(v), c(c), f(0), r(0){}
	int residual(){
		if(f<0)
			return -f;
		return c-f;
	}
};
const int inf=0x3f3f3f3f;
vector<Edge> adj[205];
int level[205], idx[205];
bool bfs(int s, int t){
	memset(level, -1, sizeof(level));
	level[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].v;
			int r=adj[now][i].residual();
			if(r>0&&level[there]==-1){
				level[there]=level[now]+1;
				q.push(there);
			}
		}
	}
	return level[t]==-1;
}
int dfs(int now, int t, int amt){
	if(now==t)
		return amt;
	for(int &i=idx[now];i<adj[now].size();i++){
		int there=adj[now][i].v;
		int r=adj[now][i].residual();
		if(r>0&&level[there]==level[now]+1){
			int temp=dfs(there, t, min(amt, r));
			if(temp!=0){
				adj[now][i].f+=temp;
				adj[there][adj[now][i].r].f-=temp;
				return temp;
			}
		}
	}
	return 0;
}
int flow(int s, int t){
	int ret=0;
	while(true){
		if(bfs(s, t))
			break;
		memset(idx, 0, sizeof(idx));
		while(true){
			int f=dfs(s, t, inf);
			if(f==0)
				break;
			ret+=f;
		}
	}
	return ret;
}
void make_edge(int u, int v, int c){
	Edge uv(v, c);
	Edge vu(u, 0);
	uv.r=adj[v].size();
	vu.r=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	int s, t;
	s=0;
	t=n+m+1;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		make_edge(s, i, x);
	}
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d", &x);
		make_edge(i+n, t, x);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d", &x);
			make_edge(j, i+n, x);
		}
	printf("%d\n", flow(s, t));
	return 0;
}

