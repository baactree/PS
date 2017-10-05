#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > adj[1005];
int dist[1005][1005];
int s,e;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d%d",&s,&e);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	memset(dist,0x3f,sizeof(dist));
	dist[s][0]=0;
	for(int i=1;i<1005;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<adj[j].size();k++){
				int there=adj[j][k].first;
				int cost=adj[j][k].second;
				dist[there][i]=min(dist[there][i],dist[j][i-1]+cost);
			}
		}
	}
	printf("%d\n",*min_element(dist[e],dist[e]+1005));
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<1005;j++)
			dist[e][j]+=x*j;
		printf("%d\n",*min_element(dist[e],dist[e]+1005));
	}
	return 0;
}