#include <bits/stdc++.h>
using namespace std;
int n,m,q;
vector<pair<int,int> > adj[505];
int dist[505][505];
int arr[505];
const int inf=0x3f3f3f3f;
void dijk(int st){
	for(int i=1;i<=n;i++)
		dist[st][i]=inf;
	priority_queue<pair<int,int> > pq;
	pq.push({-arr[st],st});
	dist[st][st]=arr[st];
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[st][now]<cost)
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			if(arr[st]<arr[there])
				continue;
			int there_cost=adj[now][i].second+cost;
			if(dist[st][there]>there_cost){
				dist[st][there]=there_cost;
				pq.push({-there_cost,there});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<m;i++){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}
	for(int i=1;i<=n;i++)
		dijk(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dist[i][j]=min(dist[i][j],dist[k][i]+dist[k][j]-arr[k]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dist[i][j]=min(dist[i][j],dist[j][i]);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",dist[a][b]==inf?-1:dist[a][b]);
	}
	return 0;
}