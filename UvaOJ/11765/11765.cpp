#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int v,c,f,r;
    Edge(){}
    Edge(int v,int c):v(v),c(c),f(0),r(0){}
    int residual(){
        if(f<0)
            return -f;
        return c-f;
    }
};
vector<Edge> adj[205];
pair<int,int> arr[205];
void make_edge(int u,int v,int c){
    Edge uv(v,c);
    Edge vu(u,0);
    uv.r=adj[v].size();
    vu.r=adj[u].size();
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
int level[205];
int idx[205];
bool bfs(int s,int t){
    memset(level,-1,sizeof(level));
    queue<int> q;
    level[s]=0;
    q.push(s);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i].v;
            int r=adj[now][i].residual();
            if(r>0&&level[there]==-1){
                level[there]=level[now]+1;
                q.push(there);
            }
        }
    }
    return level[t]==-1;
}
int dfs(int now,int t,int amt){
    if(now==t)
        return amt;
    for(int &i=idx[now];i<adj[now].size();i++){
        int there=adj[now][i].v;
        int r=adj[now][i].residual();
        if(r>0&&level[there]==level[now]+1){
            int ret=dfs(there,t,min(r,amt));
            if(ret>0){
                adj[now][i].f+=ret;
                adj[there][adj[now][i].r].f-=ret;
                return ret;
            }
        }
    }
    return 0;
}
const int inf=0x3f3f3f3f;
int flow(int s,int t){
    int ret=0;
    while(true){
        if(bfs(s,t))
            break;
        memset(idx,0,sizeof(idx));
        int cnt=0;
        while(true){
            int k=dfs(s,t,inf);
            if(k==0)
                break;
            ret+=k;
        }
    }
    return ret;
}
int n,m;
int main(){
    int testcase;
    scanf("%d",&testcase);
   
    while(testcase--){
        for(int i=0;i<205;i++)
            adj[i].clear();
        scanf("%d%d",&n,&m);
        int s=0;
        int t=n+1;
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i].first);
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i].second);
        for(int i=1;i<=n;i++){
            int in;
            scanf("%d",&in);
            if(in!=-1)
                make_edge(s,i,arr[i].first);
            else
                make_edge(s,i,inf);
            if(in!=1)
                make_edge(i,t,arr[i].second);
            else 
                make_edge(i,t,inf);
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            make_edge(a,b,c);
            make_edge(b,a,c);
        }
        printf("%d\n",flow(s,t));
    }
    return 0;
}