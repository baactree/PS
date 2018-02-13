#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int dist[105][10005];
vector<pair<int,pair<int,int> > > adj[105];
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d%d%d",&k,&n,&m);
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		adj[a].push_back({b,{c,d}});
		adj[b].push_back({a,{c,d}});
	}
	memset(dist,0x3f,sizeof(dist));
	priority_queue<pair<int,pair<int,int> > > pq;
	pq.push({0,{1,0}});
	dist[1][0]=0;
	while(!pq.empty()){
		int now=pq.top().second.first;
		int pay=pq.top().second.second;
		int cost=-pq.top().first;
		pq.pop();
		if(dist[now][pay]<cost)
			continue;
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int there_cost=adj[now][i].second.first+cost;
			int there_pay=adj[now][i].second.second+pay;
			if(there_pay<=k&&dist[there][there_pay]>there_cost){
				dist[there][there_pay]=there_cost;
				pq.push({-there_cost,{there,there_pay}});
			}
		}
	}
	int ans=inf;
	for(int i=0;i<=k;i++)
		ans=min(ans,dist[n][i]);
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}