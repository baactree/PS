// =====================================================================================
// 
//       Filename:  11495.cpp
//        Created:  2017년 05월 13일 22시 36분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int v, flow, capacity;
	int rv;
	Edge(){}
	Edge(int v, int capacity):v(v), flow(0), capacity(capacity), rv(NULL){}
	inline int get_residual(){
		if(flow<0)
			return -flow;
		return capacity-flow;
	}
};
int n, m;
int mat[50][50];
vector<Edge> adj[3000];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int idx[3000];
int level[3000];
const int inf=0x3f3f3f3f;
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
void bfs(int s, int t){
	memset(level, -1, sizeof(level));
	queue<int> q;
	q.push(s);
	level[s]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].v;
			int r=adj[now][i].get_residual();
			if(r>0&&level[there]==-1){
				level[there]=level[now]+1;
				q.push(there);
			}
		}
	}
}
int dfs(int now, int t, int f){
	if(now==t)
		return f;
	for(int &i=idx[now];i<adj[now].size();i++){
		int there=adj[now][i].v;
		int r=adj[now][i].get_residual();
		if(r>0&&level[there]==level[now]+1){
			int ret=dfs(there, t, min(r, f));
			if(ret>0){
				adj[now][i].flow+=ret;
				int rev=adj[now][i].rv;
				adj[there][rev].flow-=ret;
				return ret;
			}
		}
	}
	return 0;
}
int flow(int s, int t){
	int ret=0;
	while(true){
		memset(idx, 0, sizeof(idx));
		bfs(s, t);
		if(level[t]==-1)
			break;
		while(true){
			int f=dfs(s, t, inf);
			ret+=f;
			if(f==0)
				break;
		}	
	}
	return ret;
}
extern inline void make_edge(int u, int v, int capa){
	Edge uv=Edge(v, capa);
	Edge vu=Edge(u, 0);
	uv.rv=adj[v].size();
	vu.rv=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<3000;i++)
			adj[i].clear();
		scanf("%d%d", &n, &m);
		int sum=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				int in;
				scanf("%d", &in);
				sum+=in;
				if((i+j)&1)
					make_edge(n*m, i*m+j, in);
				else
					make_edge(i*m+j, n*m+1, in);
				for(int k=0;k<4;k++){
					int x=i+dx[k];
					int y=j+dy[k];
					if((i+j)&1&&safe(x, y))
						make_edge(i*m+j, x*m+y, inf);
				}
			}
		int f=flow(n*m, n*m+1);
		int ans=sum-f;
		printf("%d\n", ans);
	}
	return 0;
}

