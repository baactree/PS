#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int v,c,f,w,r;
    Edge(){}
    Edge(int v,int c,int w):v(v),c(c),w(w),f(0),r(0){}
    int residual(){
        if(f<0)
            return -f;
        return c-f;
    }
    void push(int amt);
    int weight();
};
vector<Edge> adj[505];
void Edge::push(int amt){
    f+=amt;
    adj[v][r].f-=amt;
}
int Edge::weight(){
    if(f<0)
        return -adj[v][r].w;
    return w;
}
void make_edge(int u,int v,int c,int w){
    Edge uv(v,c,w);
    Edge vu(u,0,0);
    uv.r=adj[v].size();
    vu.r=adj[u].size();
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
const int inf=0x3f3f3f3f;
int dist[505];
int trip[505];
int idx[505];
int par[505];
int amount[505];
int mcmf(int s,int t){
    int ret=0;
    while(true){
        memset(dist,0x3f,sizeof(dist));
        dist[s]=0;
        trip[s]=true;
        amount[s]=inf;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            trip[now]=false;
            for(int i=0;i<adj[now].size();i++){
                int there=adj[now][i].v;
                int r=adj[now][i].residual();
                if(r>0){
                    int w=adj[now][i].weight();
                    if(dist[there]>dist[now]+w){
                        dist[there]=dist[now]+w;
                        par[there]=now;
                        idx[there]=i;
                        amount[there]=min(amount[now],r);
                        if(!trip[there]){
                            trip[there]=true;
                            q.push(there);
                        }
                    }
                }
            }
        }
        if(dist[t]==inf)
            break;
        ret+=dist[t]*amount[t];
        int now=t;
        while(now!=s){
            int p=par[now];
            adj[p][idx[now]].push(amount[t]);
            now=p;
        }
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        for(int i=0;i<505;i++)
            adj[i].clear();
        int n,m;
        scanf("%d%d",&n,&m);
        int s=0;
        int t=n+1;
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            make_edge(a,b,inf,1);
            make_edge(b,a,inf,1);
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x)
                make_edge(i,t,1,0);
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x)
                make_edge(s,i,1,0);
        }
        printf("%d\n",mcmf(s,t));
    }
    return 0;
}