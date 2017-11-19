#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,q;
pair<int,pair<int,int> >  arr[500005];
pair<pair<int,int>,pair<int,int> > edge[500005];
vector<pair<int,int> > adj[500005];
int p[500005];
int par[500005][20];
int depth[500005];
int dp[500005][20];
bool used[500005];
int find(int x){
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	p[x]=y;
}
void dfs(int now,int parent,int d){
	depth[now]=d;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int weight=adj[now][i].second;
		if(there==parent)
			continue;
		dp[there][0]=weight;
		par[there][0]=now;
		for(int i=1;i<20;i++){
			par[there][i]=par[par[there][i-1]][i-1];
			dp[there][i]=min(dp[there][i-1],dp[par[there][i-1]][i-1]);
		}
		dfs(there,now,d+1);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])
		swap(x,y);
	int ret=inf;
	for(int i=19;i>=0;i--){
		if(depth[x]-depth[y]>=(1<<i)){
			ret=min(ret,dp[x][i]);
			x=par[x][i];
		}
	}
	if(x==y)
		return ret;
	for(int i=19;i>=0;i--){
		if(par[x][i]!=par[y][i]){
			ret=max(ret,dp[x][i]);
			ret=max(ret,dp[y][i]);
			x=par[x][i];
			y=par[y][i];
		}
	}
	return max({ret,dp[x][0],dp[y][0]});
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		arr[i+1]={d,{a,b}};
		edge[i]={{d,i+1},{a,b}};
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	sort(edge,edge+m);
	for(int i=0;i<m;i++){
		int idx=edge[i].first.second;
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		int w=edge[i].first.first;
		if(find(u)==find(v))
			continue;
		merge(u,v);
		used[idx]=true;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dfs(1,0,0);
	scanf("%d",&q);
	while(q--){
		int k;
		scanf("%d",&k);
		bool flag=true;
		while(k--){
			int t;
			scanf("%d",&t);
			if(used[t])
				continue;
			int u=arr[t].second.first;
			int v=arr[t].second.second;
			int w=arr[t].first;
			if(w==lca(u,v))
				continue;
			flag=false;
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}