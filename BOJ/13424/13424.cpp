#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > adj[105];
int dist[105];
vector<int> f;
int dijk(int st){
    memset(dist,0x3f,sizeof(dist));
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
            if(there_cost<dist[there]){
                dist[there]=there_cost;
                pq.push({-there_cost,there});
            }
        }
    }
    int ret=0;
    for(int i=0;i<f.size();i++){
        ret+=dist[f[i]];
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        for(int i=0;i<105;i++)
            adj[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }
        scanf("%d",&k);
        f.clear();
        for(int i=0;i<k;i++){
            int in;
            scanf("%d",&in);
            f.push_back(in);
        }
        int min_value=0x3f3f3f3f;
        int ans=0;
        for(int i=1;i<=n;i++){
            int t=dijk(i);
            if(min_value>t){
                min_value=t;
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}