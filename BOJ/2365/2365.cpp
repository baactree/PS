#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int v,c,f,rev;
    Edge(){}
    Edge(int v,int c):v(v),c(c),f(0),rev(0){}
    int residual(){
        if(f<0)
            return -f;
        return c-f;
    }
};
vector<Edge> adj[105];
void make_edge(int u,int v,int c){
    Edge uv(v,c);
    Edge vu(u,0);
    uv.rev=adj[v].size();
    vu.rev=adj[u].size();
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
int n;
int r[55],c[55];
int sum;
int mat[55][55];
const int inf=0x3f3f3f3f;
int level[105];
int idx[105];
bool bfs(int s,int t){
    memset(level,-1,sizeof(level));
    level[s]=0;
    queue<int> q;
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
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].v;
        int r=adj[now][i].residual();
        if(r>0&&level[there]==level[now]+1){
            int temp=dfs(there,t,min(amt,r));
            if(temp>0){
                adj[now][i].f+=temp;
                adj[there][adj[now][i].rev].f-=temp;
                return temp;
            }
        }
    }
    return 0;
}
int flow(int s,int t){
    int ret=0;
    while(true){
        if(bfs(s,t))
            break;
        memset(idx,0,sizeof(idx));
        while(true){
            int f=dfs(s,t,inf);
            ret+=f;
            if(f==0)
                break;
        }
    }
    return ret;
}
bool possi(int x){
    for(int i=0;i<105;i++)
        adj[i].clear();
    int s,t;
    s=0;
    t=n*2+1;
    for(int i=1;i<=n;i++)
        make_edge(s,i,r[i]);
    for(int i=1;i<=n;i++)
        make_edge(i+n,t,c[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            make_edge(i,j+n,x);
        }
    int f=flow(s,t);
    return f==sum;
}
void get_ans(){
    for(int u=1;u<=n;u++){
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].v-n;
            int c=adj[u][j].c;
            int f=adj[u][j].f;
            if(v>=1&&v<=n&&c>0)
                mat[u][v]=f;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        sum+=r[i];
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int le,ri,mid,ans;
    le=0;
    ri=10000;
    ans=-1;
    while(le<=ri){
        mid=(le+ri)/2;
        if(possi(mid)){
            get_ans();
            ans=mid;
            ri=mid-1;
        }
        else
            le=mid+1;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    return 0;
}