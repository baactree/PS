#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int ans[10005];
bool trip[10005];
bool trip2[10005];
int cnt[10005];
vector<int> adj[10005];
pair<int,int> dfs(int now,int par){
    trip[now]=true;
    pair<int,int> ret={0,now};
    cnt[now]=1;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(there==par||trip[there])
            continue;
        auto p=dfs(there,now);
        p.first++;
        ret=max(ret,p);
        cnt[now]+=cnt[there];
    }
    return ret;
}
int dfs2(int now,int par){
    trip2[now]=true;
    int ret=0;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(there==par||trip2[there])
            continue;
        ret=max(ret,dfs2(there,now)+1);
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        for(int i=0;i<10005;i++)
            adj[i].clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(cnt,0,sizeof(cnt));
        memset(ans,0x3f,sizeof(ans));
        memset(trip,0,sizeof(trip));
        memset(trip2,0,sizeof(trip2));
        for(int i=1;i<=n;i++){
            if(!trip[i]){
                auto f=dfs(i,-1);
                int k=dfs2(f.second,-1);
                int p=cnt[i];
                for(int j=0;j<=k;j++)
                    ans[j+1]=min(ans[j+1],j);
                for(int j=k+1;j<=p;j++)
                    ans[j]=min(ans[j],k+(j-(k+1))*2);
            }
        }
        printf("Case %d:\n",tc);
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int k;
            scanf("%d",&k);
            if(ans[k]==0x3f3f3f3f)
                printf("impossible\n");
            else
                printf("%d\n",ans[k]);
        }
    }
    return 0;
}