#include <bits/stdc++.h>
using namespace std;
int n,v,e;
int st1,st2;
int dist[1005];
vector<int> vec;
vector<pair<int,int> > adj[1005];
int dijk(int st){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<pair<int,int> > pq;
    dist[st]=0;
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
    int ret=0;
    for(int i=0;i<vec.size();i++){
        if(dist[vec[i]]==0x3f3f3f3f)
            ret--;
        ret+=dist[vec[i]];
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&n,&v,&e);
    scanf("%d%d",&st1,&st2);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        vec.push_back(in);
    }
    for(int i=0;i<e;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    int ans=0;
    ans+=dijk(st1);
    ans+=dijk(st2);
    printf("%d\n",ans);
    return 0;
}