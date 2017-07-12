#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int> > adj[10005];
int distx[10005];
int disty[10005];
int x,y;
int vertex[10005];
const int inf=2e9+5;
void dijk(int st,int *dist){
    memset(dist,0x3f,sizeof(distx));
    dist[st]=0;
    priority_queue<pair<int,int> > pq;
    pq.push({0,st});
    while(!pq.empty()){
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        if(cost>dist[now])
            continue;
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i].first;
            int there_cost=adj[now][i].second+cost;
            if(dist[there]>there_cost){
                dist[there]=there_cost;
                pq.push({-there_cost,there});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    int k;
    scanf("%d%d",&k,&x);
    while(k--){
        int in;
        scanf("%d",&in);
        adj[0].push_back({in,0});
        vertex[in]=1;
    }
    scanf("%d%d",&k,&y);
    while(k--){
        int in;
        scanf("%d",&in);
        adj[n+1].push_back({in,0});
        vertex[in]=2;
    }
    dijk(0,distx);
    dijk(n+1,disty);
    int ans=inf;
    for(int i=1;i<=n;i++){
        if(vertex[i]==0&&distx[i]<=x&&disty[i]<=y){
            ans=min(ans,distx[i]+disty[i]);
        }
    }
    printf("%d\n",ans==inf?-1:ans);
    return 0;
}