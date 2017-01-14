#include "bits/stdc++.h"
using namespace std;
int depth[50001];
int weight[40001];
vector<pair<int,int> > edge[50001];
int par[50001][16];
int N,M;
void dfs(int now,int parent,int dep,int w){
    depth[now]=dep;
    weight[now]=w;
    for(int i=0;i<edge[now].size();i++){
        int there=edge[now][i].first;
        int cost=edge[now][i].second;
        if(there==parent)
            continue;
        par[there][0]=now;
        for(int i=1;i<16;i++)
            par[there][i]=par[par[there][i-1]][i-1];
        dfs(there,now,dep+1,w+cost);
    }
    
}
int lca(int a,int b){
    if(depth[a]<depth[b])
        swap(a,b);
    for(int i=15;i>=0;i--){
        if((1<<i)<=depth[a]-depth[b]){
            a=par[a][i];
        }
    }
    if(a==b)
        return a;
    for(int i=15;i>=0;i--){
        if(par[a][i]!=par[b][i]){
            a=par[a][i];
            b=par[b][i];
        }
    }
    return par[a][0];
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        edge[a].push_back({b,d});
        edge[b].push_back({a,d});
    }
    dfs(1,0,0,0);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int temp=lca(a,b);
        printf("%d\n",weight[a]+weight[b]-2*(weight[temp]));
    }
    return 0;
}