#include "bits/stdc++.h"
using namespace std;
int depth[50001];
vector<int> edge[50001];
int par[50001][16];
int N,M;
void dfs(int now,int parent,int dep){
    depth[now]=dep;
    for(int i=0;i<edge[now].size();i++){
        int there=edge[now][i];
        if(there==parent)
            continue;
        par[there][0]=now;
        for(int i=1;i<16;i++)
            par[there][i]=par[par[there][i-1]][i-1];
        dfs(there,now,dep+1);
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
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1,0,0);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
}