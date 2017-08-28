// =====================================================================================
// 
//       Filename:  5651.cpp
//        Created:  2017년 08월 23일 15시 40분 47초
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
	int residual(){
		if(f<0)
			return -f;
		return c-f;
	}
};
vector<Edge> adj[305];
void make_edge(int u, int v, int c){
	Edge uv(v, c);
	Edge vu(u, 0);
	uv.r=adj[v].size();
	vu.r=adj[u].size();
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
int level[305];
int idx[305];
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
		int r=adj[now][i].residual();
		if(level[there]==level[now]+1&&r>0){
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
int n, m;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<305;i++)
			adj[i].clear();
		scanf("%d%d", &n, &m);
		for(int i=0;i<m;i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			make_edge(a, b, c);
		}
		int f=flow(1, n);
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<adj[i].size();j++){
				int there=adj[i][j].v;
				if(adj[i][j].c>0&&adj[i][j].residual()==0){
					if(bfs(i, there))
						cnt++;
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}

