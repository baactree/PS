#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<int> adj[100005];
int dep[100005];
int par[100005][17];
void dfs(int now,int parent,int depth){
    dep[now]=depth;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(there==parent)
            continue;
        par[there][0]=now;
        for(int j=1;j<17;j++)
            par[there][j]=par[par[there][j-1]][j-1];
        dfs(there,now,depth+1);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])
        swap(u,v);
    for(int i=16;i>=0;i--)
        if(dep[u]-dep[v]>=1<<i)
            u=par[u][i];
    if(u==v)
        return u;
    for(int i=16;i>=0;i--)
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    return par[u][0];
}
int dist(int u,int v,int l){
    return dep[u]+dep[v]-dep[l]*2;
}
int solve(int s,int t,int f){
    int p=lca(s,f);
    if(p==s){
        int q=lca(t,f);
        int d=dist(s,f,p)+1;
        int k=dep[q]-dep[p];
        return max(d-max(0,k),1);
    }
    else if(p==f){
        int q=lca(t,s);
        int d=dist(s,f,p)+1;
        int k=dep[q]-dep[p];
        return min(d,k+1);
    }
    else{
        int q=lca(t,p);
        if(q!=p)
            return dist(p,f,p)+1;
        else{
            int sp=lca(t,s);
            int fp=lca(t,f);
            if(sp==s)
                return dist(s,f,p)+1;
            else if(fp==f)
                return 1;
            else if(sp==p&&fp==p)
                return dist(p,f,p)+1;
            else if(sp==p)
                return dep[f]-dep[fp]+1;
            else
                return dist(s,f,p)+1-(dep[s]-dep[sp]);
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1,0,0);
    while(q--){
        vector<int> vec;
        for(int i=0;i<3;i++){
            int in;
            scanf("%d",&in);
            vec.push_back(in);
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        do{
            ans=max(ans,solve(vec[0],vec[1],vec[2]));
        }while(next_permutation(vec.begin(),vec.end()));
        printf("%d\n",ans);
    }
    return 0;
}