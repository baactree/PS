#include <bits/stdc++.h>
using namespace std;
vector<int> adj[505];
vector<int> group[505];
bool trip[505];
int n,m;
void dfs(int now,int idx){
	group[idx].push_back(now);
	trip[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(!trip[there])
			dfs(there,idx);
	}
}
int main(){
	int tc=1;
	while(true){
		for(int i=0;i<505;i++){
			adj[i].clear();
			group[i].clear();
			trip[i]=0;
		}
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int idx=0;
		for(int i=1;i<=n;i++){
			if(!trip[i]){
				dfs(i,idx);
				idx++;
			}
		}
		int ans=0;
		for(int i=0;i<idx;i++){
			int cnt=0;
			for(int j=0;j<group[i].size();j++){
				int now=group[i][j];
				cnt+=adj[now].size();
			}
			if(cnt/2+1==group[i].size())
				ans++;
		}
		printf("Case %d: ",tc++);
		if(ans==0)
			printf("No trees.\n");
		else if(ans==1)
			printf("There is one tree.\n");
		else
			printf("A forest of %d trees.\n",ans);
	}
	return 0;
}