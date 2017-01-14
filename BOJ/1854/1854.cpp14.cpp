#include "bits/stdc++.h"
using namespace std;
vector<pair<int,int> > edge[1001];
int N,M,K;
vector<priority_queue<int> > dist(1001);
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        edge[a].push_back({b,d});
    }
    priority_queue<pair<int,int> > pq;
    pq.push({0,1});
    dist[1].push(0);
    while(!pq.empty()){
        int now=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        for(int i=0;i<edge[now].size();i++){
            int there=edge[now][i].first;
            int there_cost=edge[now][i].second+cost;
            if(dist[there].size()<K){
                dist[there].push(there_cost);
                pq.push({-there_cost,there});
            }
            else if(dist[there].top()>there_cost){
                dist[there].pop();
                dist[there].push(there_cost);
                pq.push({-there_cost,there});
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(dist[i].size()<K)
            printf("-1\n");
        else
            printf("%d\n",dist[i].top());
    }
    return 0;
}