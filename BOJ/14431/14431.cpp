#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > vec;
vector<pair<int,int> > adj[5000];
int dist[5000];
bool prime[10000];
int get_dist(int x,int y){
    return hypot(vec[x].first-vec[y].first,vec[x].second-vec[y].second);
}
int main(){
    prime[0]=prime[1]=true;
    for(int i=2;i<10000;i++){
        if(!prime[i]){
            for(int j=i+i;j<10000;j+=i)
                prime[j]=true;
        }
    }
    for(int i=0;i<2;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vec.push_back({x,y});
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vec.push_back({x,y});
    }
    for(int i=0;i<vec.size();i++)
        for(int j=i+1;j<vec.size();j++){
            int d=get_dist(i,j);
            if(!prime[d]){
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
    memset(dist,0x3f,sizeof(dist));
    priority_queue<pair<int,int> > pq;
    pq.push({0,0});
    dist[0]=0;
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
    printf("%d\n",dist[1]==0x3f3f3f3f?-1:dist[1]);
    return 0;
}