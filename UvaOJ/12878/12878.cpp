#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[10005];
int dist[10005];
vector<int> par[10005];
bool trip[10005];
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<10005;i++){
            adj[i].clear();
            par[i].clear();
        }
        memset(trip,0,sizeof(trip));
        for(int i=0;i<m;i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }
        memset(dist,0x3f,sizeof(dist));
        dist[0]=0;
        priority_queue<pair<int,int> > pq;
        pq.push({0,0});
        while(!pq.empty()){
            int now=pq.top().second;
            int cost=-pq.top().first;
            pq.pop();
            if(dist[now]<cost)
                continue;
            for(int i=0;i<adj[now].size();i++){
                int there=adj[now][i].first;
                int there_cost=adj[now][i].second+cost;
                if(dist[there]>there_cost){
                    dist[there]=there_cost;
                    pq.push({-there_cost,there});
                    par[there].clear();
                    par[there].push_back(now);
                }
                else if(dist[there]==there_cost){
                    par[there].push_back(now);
                }
            }
        }
        queue<int> q;
        q.push(n-1);
        trip[n-1]=true;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=0;i<par[now].size();i++){
                int there=par[now][i];
                if(!trip[there]){
                    trip[there]=true;
                    q.push(there);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                int there=adj[i][j].first;
                int weight=adj[i][j].second;
                if(!trip[there]||!trip[i])
                    continue;
                if(dist[there]==dist[i]-weight){
                    ans+=weight*2;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}