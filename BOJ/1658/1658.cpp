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
const int inf=0x3f3f3f3f;
vector<Edge> adj[2000];
void make_edge(int u,int v,int c){
    Edge uv(v,c);
    Edge vu(u,0);
    uv.rev=adj[v].size();
    vu.rev=adj[u].size();
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
int m,n;
// 1~n 사람
// n+1 ~ n+m 돼지우리
// 0 s n+m+1 t
vector<int> p[1005];
int level[2000];
int idx[2000];
bool bfs(int s,int t){
    memset(level,-1,sizeof(level));
    queue<int> q;
    q.push(s);
    level[s]=0;
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
            int temp=dfs(there,t,min(amt,r));
            if(temp!=0){
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
int main(){
    scanf("%d%d",&m,&n);
    int s,t;
    s=0;
    t=n+m+1;
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        make_edge(n+i,t,x);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        set<int> s;
        vector<int> arr;
        while(k--){
            int in;
            scanf("%d",&in);
            arr.push_back(in);
            for(int j=0;j<p[in].size();j++)
                s.insert(p[in][j]);
        }
        for(auto it=s.begin();it!=s.end();it++)
            make_edge(i,*it,inf);
        int x;
        scanf("%d",&x);
        make_edge(0,i,x);
        for(int j=0;j<arr.size();j++){
            p[arr[j]].push_back(i);
            make_edge(i,arr[j]+n,inf);
        }
    }
    printf("%d\n",flow(s,t));
    return 0;
}