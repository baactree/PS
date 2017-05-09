// =====================================================================================
// 
//       Filename:  13510.cpp
//        Created:  2017년 05월 08일 23시 41분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Sgtree{
	vector<int> tree;
	int n;
	Sgtree(){}
	Sgtree(int n):n(n){
		tree=vector<int>(n*4, -1);
	}
	void update(int idx, int val, int nodele, int noderi, int node){
		if(idx<nodele||noderi<idx)
			return;
		if(nodele==noderi){
			tree[node]=val;
			return;
		}
		int mid=(nodele+noderi)/2;
		update(idx, val, nodele, mid, node*2);
		update(idx, val, mid+1, noderi, node*2+1);
		tree[node]=max(tree[node*2], tree[node*2+1]);
	}
	void update(int idx, int val){
		update(idx, val, 0, n-1, 1);
	}
	int query(int le, int ri, int nodele, int noderi, int node){
		if(le>noderi||ri<nodele)
			return -1;
		if(le<=nodele&&noderi<=ri)
			return tree[node];
		int mid=(nodele+noderi)/2;
		return max(query(le, ri, nodele, mid, node*2), query(le, ri, mid+1, noderi, node*2+1));
	}
	int query(int le, int ri){
		return query(le, ri, 0, n-1, 1);
	}
};
struct Edge{
	int v, w, idx;
};
int n, q;
vector<Edge> adj[100001];
int parent[100001][17];
int weight[100001];
int edge[100001];
int depth[100001];
int subtree[100001];
vector<vector<int> > heavy_paths;
int heavy_path_index[100001];
vector<Sgtree> heavy_path_sgtree;
int dfs(int now, int par, int dep){
	depth[now]=dep;
	subtree[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].v;
		int idx=adj[now][i].idx;
		if(there==par)
			continue;
		weight[there]=adj[now][i].w;
		parent[there][0]=now;
		edge[idx]=there;
		for(int j=1;j<17;j++)
			parent[there][j]=parent[parent[there][j-1]][j-1];
		subtree[now]+=dfs(there, now, dep+1);
	}
	return subtree[now];
}
void make_heavy_paths(int root){
	queue<pair<int, int> > q;
	q.push({root, 0});
	while(!q.empty()){
		int now=q.front().first;
		int par=q.front().second;
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].v;
			if(there==par)
				continue;
			q.push({there, now});
		}
		if(now==root)
			continue;
		if(subtree[now]*2>=subtree[par]&&par!=root){
			int idx=heavy_path_index[now]=heavy_path_index[par];
			heavy_paths[idx].push_back(now);
		}
		else{
			heavy_path_index[now]=heavy_paths.size();
			heavy_paths.push_back(vector<int>(2));
			heavy_paths.back()[0]=par;
			heavy_paths.back()[1]=now;
		}
	}
}
void init_heavy_paths(){
	for(int i=0;i<heavy_paths.size();i++){
		int m=heavy_paths[i].size();
		heavy_path_sgtree.push_back(Sgtree(m-1));
		for(int j=0;j<m-1;j++)
			heavy_path_sgtree.back().update(j, weight[heavy_paths[i][j+1]]);
	}
}
int find_idx(int hidx, int v){
	int top=heavy_paths[hidx][0];
	return depth[v]-depth[top]-1;
}
void update(int idx, int cost){
	int v=edge[idx];
	int hidx=heavy_path_index[v];
	int tidx=find_idx(hidx, v);
	heavy_path_sgtree[hidx].update(tidx, cost);
}
int lca(int u, int v){
	if(depth[u]<depth[v])
		swap(u, v);
	for(int i=16;i>=0;i--)
		if(depth[u]-depth[v]>=1<<i){
			u=parent[u][i];
		}
	if(u==v)
		return u;
	for(int i=16;i>=0;i--)
		if(parent[u][i]!=parent[v][i]){
			u=parent[u][i];
			v=parent[v][i];
		}
	return parent[u][0];
}
int heavy_query(int u, int v){
	if(u==v)
		return -1;
	if(heavy_path_index[u]==heavy_path_index[v]){
		int hidx=heavy_path_index[u];
		int uidx=find_idx(hidx, u);
		int vidx=find_idx(hidx, v);
		return heavy_path_sgtree[hidx].query(uidx+1, vidx);
	}
	int hidx=heavy_path_index[v];
	int top=heavy_paths[hidx][0];
	int vidx=find_idx(hidx, v);
	return max(heavy_query(u, top), heavy_path_sgtree[hidx].query(0, vidx));
}
int query(int u, int v){
	int t=lca(u, v);
	return max(heavy_query(t, u), heavy_query(t, v));
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d, i});
		adj[b].push_back({a, d, i});
	}
	dfs(1, 0, 0);
	make_heavy_paths(1);
	init_heavy_paths();
	scanf("%d", &q);
	for(int i=0;i<q;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1)
			update(b, c);
		else
			printf("%d\n", query(b, c));
	}
	return 0;
}

