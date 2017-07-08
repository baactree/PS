#include <bits/stdc++.h>
using namespace std;
int n,m;
int dist[1005];
int par[1005];
vector<pair<int,int> > adj[1005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    priority_queue<pair<int,int> > pq;
    pq.push({0,1});
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
                par[there]=now;
                pq.push({-there_cost,there});
            }
        }
    }
    vector<pair<int,int> > ans;
    for(int i=2;i<=n;i++){
        int now=i;
        while(now!=1){
            int v=now;
            int u=par[now];
            if(u>v)
                swap(u,v);
            ans.push_back({u,v});
            now=par[now];
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}