#include <bits/stdc++.h>
using namespace std;
int n,d,c;
vector<pair<int,int> > adj[10005];
int dist[10005];
const int inf=0x3f3f3f3f;
void dijk(int st){
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
            if(dist[there]>there_cost){
                dist[there]=there_cost;
                pq.push({-there_cost,there});
            }
        }
    }
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        for(int i=0;i<10005;i++)
            adj[i].clear();
        scanf("%d%d%d",&n,&d,&c);
        for(int i=0;i<d;i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            adj[b].push_back({a,d});
        }
        dijk(c);
        int cnt=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]!=inf){
                cnt++;
                ans=max(ans,dist[i]);
            }
        }
        printf("%d %d\n",cnt,ans);
    }
    return 0;
}