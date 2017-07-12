#include <bits/stdc++.h>
using namespace std;
int n,m;
int color[1005];
vector<int> adj[1005];
bool dfs(int now,int mode){
    if(color[now]!=-1)
        return color[now]!=mode;
    color[now]=mode;
    bool ret=false;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        ret|=dfs(there,1-mode);
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        for(int i=0;i<1005;i++)
            adj[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(color,-1,sizeof(color));
        bool flag=false;
        for(int i=1;i<=n;i++)
            if(color[i]==-1)
                flag|=dfs(i,0);
        printf("%s\n",flag?"impossible":"possible");
    }
    return 0;
}