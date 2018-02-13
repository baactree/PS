#include <bits/stdc++.h>
using namespace std;
int n,m;
int group[100005];
vector<int> adj[100005];
int arr[100005];
int min_v[100005];
void dfs(int now,int k){
	group[now]=k;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(group[there]==-1)
			dfs(there,k);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(group,-1,sizeof(group));
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(group[i]==-1){
			dfs(i,cnt);
			cnt++;
		}
	}
	memset(min_v,0x3f,sizeof(min_v));
	for(int i=1;i<=n;i++)
		min_v[group[i]]=min(min_v[group[i]],arr[i]);
	long long ans=0;
	for(int i=0;i<cnt;i++)
		ans+=min_v[i];
	printf("%lld\n",ans);
	return 0;
}