#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[2005];
void make_edge(int a,int b){
    int na=(a&1)?a-1:a+1;
    int nb=(b&1)?b-1:b+1;
    adj[na].push_back(b);
    adj[nb].push_back(a);
}
int s[2005],v[2005];
int sn,vn;
stack<int> st;
int dfs(int now){
    int ret=v[now]=vn++;
    st.push(now);
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(v[there]==-1)
            ret=min(ret,dfs(there));
        else if(s[there]==-1)
            ret=min(ret,v[there]);
    }
    if(ret==v[now]){
        while(true){
            int temp=st.top();
            st.pop();
            s[temp]=sn;
            if(temp==now)
                break;
        }
        sn++;
    }
    return ret;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<2005;i++)
            adj[i].clear();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a<0)
                a=a*-2+1;
            else
                a*=2;
            if(b<0)
                b=b*-2+1;
            else
                b*=2;
            make_edge(a,b);
        }
        make_edge(2,2);
        memset(s,-1,sizeof(s));
        memset(v,-1,sizeof(v));
        sn=vn=0;
        for(int i=1;i<=n;i++){
            if(v[i*2]==-1)
                dfs(i*2);
            if(v[i*2+1]==-1)
                dfs(i*2+1);
        }
        bool ans=true;
        for(int i=1;i<=n;i++)
            if(s[i*2]==s[i*2+1])
                ans=false;
        printf("%s\n",ans?"yes":"no");
    }
    return 0;
}