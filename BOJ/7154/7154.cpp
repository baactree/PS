#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int v,w,c,f,r;
    Edge(){}
    Edge(int v,int w,int c):v(v),w(w),c(c),f(0),r(0){}
    int residual();
    int get_cost();
    void push(int amt);
};
vector<Edge> adj[300];
int Edge::residual(){
    if(f<0)
        return -f;
    return c-f;
}
int Edge::get_cost(){
    if(f<0)
        return -adj[v][r].w;
    return w;
}
void Edge::push(int amt){
    f+=amt;
    adj[v][r].f-=amt;
}
void make_edge(int u,int v,int capacity,int cost){
    Edge uv(v,cost,capacity);
    Edge vu(u,0,0);
    uv.r=adj[v].size();
    vu.r=adj[u].size();
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
int dist[300];
int trip[300];
int idx[300];
int amount[300];
int par[300];
int mcmf(int s,int t){
    int ret=0;
    while(true){
        memset(dist,0x3f,sizeof(dist));
        memset(trip,0,sizeof(trip));
        memset(idx,0,sizeof(idx));
        memset(amount,0x3f,sizeof(amount));
        memset(par,-1,sizeof(par));
        queue<int> q;
        q.push(s);
        trip[s]=true;
        dist[s]=0;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            trip[now]=false;
            for(int i=0;i<adj[now].size();i++){
                int k=adj[now][i].residual();
                if(k>0){
                    int there=adj[now][i].v;
                    int there_cost=dist[now]+adj[now][i].get_cost();
                    if(dist[there]>there_cost){
                        dist[there]=there_cost;
                        par[there]=now;
                        idx[there]=i;
                        amount[there]=min(k,amount[now]);
                        if(!trip[there]){
                            trip[there]=true;
                            q.push(there);
                        }
                    }
                }
            }
        }
        if(dist[t]==0x3f3f3f3f)
            break;
        ret+=amount[t]*dist[t];
        int now=t;
        int amt=amount[t];
        while(now!=s){
            int p=par[now];
            int i=idx[now];
            adj[p][i].push(amt);
            now=p;
        }
    }
    return ret;
}
int n,m;
int mat[4][5]={{0,0,0,0,0},{0,4,3,2,1},{0,8,7,6,5},{0,12,11,10,9}};
int main(){
    while(scanf("%d%d",&n,&m)==2){
        for(int i=0;i<300;i++)
            adj[i].clear();
        if(n==0&&m==0)
            break;
        int s,t;
        s=n+m;
        t=n+m+1;
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            make_edge(i,t,in,0);
        }
        for(int i=0;i<m;i++){
            int a,b,c,d,e;
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
            make_edge(s,n+i,1,0);
            make_edge(n+i,b,1,-mat[a][1]);
            make_edge(n+i,c,1,-mat[a][2]);
            make_edge(n+i,d,1,-mat[a][3]);
            make_edge(n+i,e,1,-mat[a][4]);
        }
        printf("%d\n",-mcmf(s,t));
    }
    return 0;
}