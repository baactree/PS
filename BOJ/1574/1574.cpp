#include <bits/stdc++.h>
using namespace std;
int n,m,k;
bool mat[305][305];
vector<int> adj[305];
bool trip[305];
int matched[305];
bool dfs(int now){
	if(trip[now])
		return false;
	trip[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||dfs(matched[there])){
			matched[there]=now;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		mat[a][b]=true;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!mat[i][j])
				adj[i].push_back(j);
	int ans=0;
	memset(matched,-1,sizeof(matched));
	for(int i=1;i<=n;i++){
		memset(trip,0,sizeof(trip));
		if(dfs(i))
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}