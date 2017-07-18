#include <bits/stdc++.h>
using namespace std;
int n,m;
int dist[505][505];
vector<pair<int,int> > adj[505];
void dijk(int st){
    priority_queue<pair<int,int> > pq;
    dist[st][st]=0;
    pq.push({0,st});
    while(!pq.empty()){
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i].first;
            int there_cost=adj[now][i].second+cost;
            if(dist[st][there]>there_cost){
                dist[st][there]=there_cost;
                pq.push({-there_cost,there});
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int in;
            scanf("%d",&in);
            if(in){
                adj[i].push_back({j,in});
            }
        }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++)
        dijk(i);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%s\n",dist[a][b]<=c?"Enjoy other party":"Stay here");
    }
    return 0;
}