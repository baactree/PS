#include "bits/stdc++.h"
using namespace std;
int N,M;
vector<pair<int,int> > edge[201];
int dist[201][201];
int par[201][201];
int main(){
    memset(dist,0x3f,sizeof(dist));
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        edge[a].push_back({b,d});
        edge[b].push_back({a,d});
    }
    for(int st=1;st<=N;st++){
        dist[st][st]=0;
        priority_queue<pair<int,int> > pq;
        pq.push({0,st});
        while(!pq.empty()){
            int now=pq.top().second;
            int cost=-pq.top().first;
            pq.pop();
            if(dist[st][now]<cost)
                continue;
            for(int i=0;i<edge[now].size();i++){
                int there=edge[now][i].first;
                int there_cost=edge[now][i].second+cost;
                if(dist[st][there]>there_cost){
                    dist[st][there]=there_cost;
                    if(now==st){
                        par[st][there]=there;
                    }
                    else{
                        par[st][there]=par[st][now];
                    }
                    pq.push({-there_cost,there});
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(par[i][j]==0)
                printf("- ");
            else
                printf("%d ",par[i][j]);
        }
        printf("\n");
    }
    return 0;
}