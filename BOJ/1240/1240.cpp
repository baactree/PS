// =====================================================================================
// 
//       Filename:  1240.cpp
//        Created:  2017년 04월 29일 13시 14분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[1001];
int parent[1001][11];
int depth[1001];
int dist[1001];
void dfs(int now, int par, int dep, int d){
	depth[now]=dep;
	dist[now]=d;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int cost=adj[now][i].second;
		if(there==par)
			continue;
		parent[there][0]=now;
		for(int i=1;i<=10;i++){
			parent[there][i]=parent[parent[there][i-1]][i-1];
		}
		dfs(there, now, dep+1, d+cost);
	}
}
int find(int x, int y){
	if(depth[x]<depth[y])
		swap(x, y);
	for(int i=10;i>=0;i--){
		if((1<<i)<=depth[x]-depth[y]){
			x=parent[x][i];
		}
	}
	if(x==y)
		return x;
	for(int i=10;i>=0;i--){
		if(parent[x][i]!=parent[y][i]){
			x=parent[x][i];
			y=parent[y][i];
		}
	}
	return parent[x][0];
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n-1;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	dfs(1, 0, 0, 0);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		int c=find(a, b);
		printf("%d\n", dist[a]+dist[b]-dist[c]*2);
	}
	return 0;
}

