#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[100005];
int scc[100005],dis[100005];
int in[100005];
int sn,vn;
stack<int> st;
int dfs(int now){
    int ret=dis[now]=vn++;
    st.push(now);
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(dis[there]==-1)
            ret=min(ret,dfs(there));
        else if(scc[there]==-1)
            ret=min(ret,dis[there]);
    }
    if(ret==dis[now]){
        while(true){
            int temp=st.top();
            st.pop();
            scc[temp]=sn;
            if(temp==now)
                break;
        }
        sn++;
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        for(int i=0;i<100005;i++){
            adj[i].clear();
            scc[i]=dis[i]=-1;
            in[i]=0;
        }
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }
        sn=vn=0;
        for(int i=1;i<=n;i++)
            if(dis[i]==-1)
                dfs(i);
        map<pair<int,int>,int> mp;
        for(int now=1;now<=n;now++){
            for(int i=0;i<adj[now].size();i++){
                int there=adj[now][i];
                int u=scc[now];
                int v=scc[there];
                if(u==v||mp[{u,v}])
                    continue;
                mp[{u,v}]=true;
                in[v]++;
            }
        }
        int ans=0;
        for(int i=0;i<sn;i++)
            if(!in[i])
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}