#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int> > > query[3005];
vector<int> adj[3005];
vector<int> badj[3005];
int par[3005][20];
bool trip[3005];
int ans[400005];
int n,m,q;
int find(int s,int k){
	for(int i=19;i>=0;i--)
		if(k>=1<<i){
			k-=1<<i;
			s=par[s][i];
		}
	return s;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		badj[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		sort(adj[i].begin(),adj[i].end());
	for(int i=0;i<q;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		query[b].push_back({i,{a,c}});
	}
	for(int t=1;t<=n;t++){
		memset(trip,0,sizeof(trip));
		trip[t]=true;
		queue<int> q;
		q.push(t);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int i=0;i<badj[now].size();i++){
				int there=badj[now][i];
				if(!trip[there]){
					trip[there]=true;
					q.push(there);
				}
			}
		}
		for(int i=1;i<=n;i++){
			par[i][0]=0;
			for(int j=0;j<adj[i].size();j++){
				int there=adj[i][j];
				if(trip[there]){
					par[i][0]=there;
					break;
				}
			}
		}
		par[t][0]=t;
		for(int i=1;i<20;i++)
			for(int j=1;j<=n;j++)
				par[j][i]=par[par[j][i-1]][i-1];
		for(int i=0;i<query[t].size();i++){
			int idx=query[t][i].first;
			int s=query[t][i].second.first;
			int k=query[t][i].second.second;
			if(par[s][19]!=t){
				ans[idx]=-1;
				continue;
			}
			k--;
			int temp=find(s,k);
			if(k&&find(s,k-1)==temp)
				ans[idx]=-1;
			else
				ans[idx]=temp;
		}
	}
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
	return 0;
}