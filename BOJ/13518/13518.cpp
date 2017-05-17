// =====================================================================================
// 
//       Filename:  13518.cpp
//        Created:  2017년 05월 14일 23시 32분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int in[100005];
int out[100005];
int id[200005];
int depth[100005];
int parent[100005][18];
int num[1000005];
int arr[100005];
bool on[100005];
int ans[100005];
int cur;
vector<int> adj[100005];
int sz;
int cnt;
struct Query{
	int le, ri, lca, idx;
	bool operator < (const Query &rhs)const{
		if(le/sz==rhs.le/sz)
			return ri<rhs.ri;
		return le/sz<rhs.le/sz;
	}
};
Query q[100005];

void dfs(int now, int par, int dep){
	depth[now]=dep;
	in[now]=++cur;
	id[cur]=now;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		parent[there][0]=now;
		for(int i=1;i<18;i++)
			parent[there][i]=parent[parent[there][i-1]][i-1];
		dfs(there, now, dep+1);
	}
	out[now]=++cur;
	id[cur]=now;
}
int lca(int x, int y){
	if(depth[y]>depth[x])
		swap(x, y);
	for(int i=17;i>=0;i--)
		if(depth[x]-depth[y]>=(1<<i))
			x=parent[x][i];
	if(x==y)
		return x;
	for(int i=17;i>=0;i--)
		if(parent[x][i]!=parent[y][i]){
			x=parent[x][i];
			y=parent[y][i];
		}
	return parent[x][0];
}
void update(int x){
	if(on[x]){
		num[arr[x]]--;
		if(num[arr[x]]==0)
			cnt--;
	}
	else{
		num[arr[x]]++;
		if(num[arr[x]]==1)
			cnt++;
	}
	on[x]^=1;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	sz=sqrt(cur);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if(in[u]>in[v])
			swap(u, v);
		int l=lca(u, v);
		q[i].lca=l;
		if(l==u){
			q[i].le=in[u];
			q[i].ri=in[v];
		}
		else{
			q[i].le=out[u];
			q[i].ri=in[v];
		}
		q[i].idx=i;
	}
	sort(q, q+m);
	
	int le, ri;
	le=q[0].le;
	ri=q[0].le-1;

	for(int i=0;i<m;i++){
		for(int j=le;j<q[i].le;j++)
			update(id[j]);
		for(int j=q[i].le;j<le;j++)
			update(id[j]);
		for(int j=ri+1;j<=q[i].ri;j++)
			update(id[j]);
		for(int j=q[i].ri+1;j<=ri;j++)
			update(id[j]);
		le=q[i].le;
		ri=q[i].ri;
		int l=q[i].lca;
		if(l!=id[le]&&l!=id[ri])
			update(l);
		ans[q[i].idx]=cnt;
		if(l!=id[le]&&l!=id[ri])
			update(l);
	}

	for(int i=0;i<m;i++)
		printf("%d\n", ans[i]);
	return 0;
}

