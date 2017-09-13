// =====================================================================================
// 
//       Filename:  3830.cpp
//        Created:  2017년 09월 13일 19시 52분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int p[100005][17];
int d[100005];
ll w[100005][17];
int par[100005];
char in[2];
bool chk[100005];
vector<pair<int, int> > adj[100005];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
}
void dfs(int now, int parent, int dep){
	d[now]=dep;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int weight=adj[now][i].second;
		if(there==parent)
			continue;
		p[there][0]=now;
		w[there][0]=weight;
		for(int i=1;i<17;i++){
			p[there][i]=p[p[there][i-1]][i-1];
			w[there][i]=w[there][i-1]+w[p[there][i-1]][i-1];
		}
		dfs(there, now, dep+1);
	}
}
int lca(int u, int v){
	if(d[v]>d[u])
		swap(u, v);
	for(int i=16;i>=0;i--){
		if(d[u]-d[v]>=1<<i)
			u=p[u][i];
	}
	if(u==v)
		return u;
	for(int i=16;i>=0;i--){
		if(p[u][i]!=p[v][i]){
			u=p[u][i];
			v=p[v][i];
		}
	}
	return p[u][0];
}
ll calc(int u, int v){
	int l=lca(u, v);
	ll ret=0;
	for(int i=16;i>=0;i--){
		if(d[u]-d[l]>=1<<i){
			ret-=w[u][i];
			u=p[u][i];
		}
		if(d[v]-d[l]>=1<<i){
			ret+=w[v][i];
			v=p[v][i];
		}
	}
	return ret;
}
int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==0&&m==0)
			break;
		for(int i=0;i<=n;i++){
			par[i]=i;
			adj[i].clear();
			d[i]=-1;
			chk[i]=0;
		}
		vector<pair<int, int> > query;
		while(m--){
			scanf("%s", in);
			if(in[0]=='!'){
				int a, b, c;
				scanf("%d%d%d", &a, &b, &c);
				if(find(a)==find(b))
					continue;
				adj[a].push_back({b, c});
				adj[b].push_back({a, -c});
				merge(a, b);
			}
			else{
				int a, b;
				scanf("%d%d", &a, &b);
				if(find(a)!=find(b))
					chk[query.size()]=1;
				query.push_back({a, b});
			}
		}
		for(int i=1;i<=n;i++)
			if(d[i]==-1)
				dfs(i, 0, 0);
		for(int i=0;i<query.size();i++){
			if(chk[i])
				printf("UNKNOWN\n");
			else
				printf("%lld\n", calc(query[i].first, query[i].second));
		}
	}
	return 0;
}

