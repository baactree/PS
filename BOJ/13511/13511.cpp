// =====================================================================================
// 
//       Filename:  13511.cpp
//        Created:  2017년 08월 10일 17시 16분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int depth[100005];
int parent[100005][17];
long long dist[100005];
vector<pair<int, int> > adj[100005];
void dfs(int now, int par, int dep, long long d){
	depth[now]=dep;
	dist[now]=d;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int w=adj[now][i].second;
		if(there==par)
			continue;
		parent[there][0]=now;
		for(int i=1;i<17;i++)
			parent[there][i]=parent[parent[there][i-1]][i-1];
		dfs(there, now, dep+1, d+w);
	}
}
int lca(int x, int y){
	if(depth[x]<depth[y])
		swap(x, y);
	for(int i=16;i>=0;i--)
		if(depth[x]-depth[y]>=1<<i)
			x=parent[x][i];
	if(x==y)
		return x;
	for(int i=16;i>=0;i--)
		if(parent[x][i]!=parent[y][i]){
			x=parent[x][i];
			y=parent[y][i];
		}
	return parent[x][0];
}
int calc(int x, int k){
	k--;
	for(int i=16;i>=0;i--)
		if(1<<i<=k){
			x=parent[x][i];
			k-=1<<i;
		}
	return x;
}
int query(int u, int v, int k){
	int l=lca(u, v);
	int a=depth[u]-depth[l];
	int b=depth[v]-depth[l];
	if(k<=a)
		return calc(u, k);
	if(k>a+1)
		return calc(v, b+1-(k-(a+1)));
	return l;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	dfs(1, 0, 0, 0);
	scanf("%d", &m);
	while(m--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1){
			int l=lca(b, c);
			printf("%lld\n", dist[b]+dist[c]-dist[l]*2);
		}
		else{
			int d;
			scanf("%d", &d);
			printf("%d\n", query(b, c, d));
		}
	}
	return 0;
}

