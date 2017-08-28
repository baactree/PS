// =====================================================================================
// 
//       Filename:  13569.cpp
//        Created:  2017년 08월 16일 22시 19분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
struct Edge{
	int v, c, f, r;
	Edge(){}
	Edge(int v, int c):v(v), c(c), f(0), r(0){}
	int get_residual(){
		if(f<0)
			return -f;
		return c-f;
	}
};
vector<Edge> adj[500];
int make_edge(int u, int v, int c){
	Edge uv(v, c);
	Edge vu(u, 0);
	uv.r=adj[v].size();
	vu.r=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
	return adj[u].size()-1;
}
int make_edge(int u, int v, int l, int r, int s, int t){
	int ret = make_edge(u, v, r-l);
	make_edge(s, v, l);
	make_edge(u, t, l);
	return ret;
}
int level[500];
int idx[500];
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
			int r=adj[now][i].get_residual();
			if(level[there]==-1&&r>0){
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
		int r=adj[now][i].get_residual();
		if(level[there]==level[now]+1&&r>0){
			int temp=dfs(there, t, min(amt, r));
			if(temp>0){
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
int n, m;
double mat[200][200];
double rsum[200], csum[200];
int ridx[200], cidx[200], midx[200][200];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			scanf("%lf", &mat[i][j]);
		scanf("%lf", &rsum[i]);
	}
	for(int i=0;i<m;i++)
		scanf("%lf", &csum[i]);
	int s, t, ns, nt;
	s=n+m;
	t=s+1;
	ns=t+1;
	nt=ns+1;
	for(int i=0;i<n;i++)
		ridx[i]=make_edge(s, i, floor(rsum[i]), ceil(rsum[i]), ns, nt);
	for(int i=0;i<m;i++)
		cidx[i]=make_edge(i+n, t, floor(csum[i]), ceil(csum[i]), ns, nt);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			midx[i][j]=make_edge(i, j+n, floor(mat[i][j]), ceil(mat[i][j]), ns, nt);
	make_edge(t, s, inf);
	flow(ns, nt);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d ", (int)(floor(mat[i][j])+adj[i][midx[i][j]].f));
		printf("%d\n", (int)(floor(rsum[i])+adj[s][ridx[i]].f));
	}
	for(int i=0;i<m;i++)
		printf("%d ", (int)(floor(csum[i])+adj[i+n][cidx[i]].f));
	printf("\n");
	return 0;
}

