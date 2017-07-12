#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,b;
int d[5005],c[5005];
vector<int> adj[5005];
ll f[5005][5005];
ll g[5005][5005];
ll dp[5005];
int cnt[5005];
vector<int> merge(vector<int> a,vector<int> b){
    vector<int> ret;
    int aidx,bidx;
    aidx=bidx=0;
    while(aidx<a.size()||bidx<b.size()){
        if(bidx==b.size()||(aidx<a.size()&&a[aidx]<b[bidx]))
            ret.push_back(a[aidx++]);
        else
            ret.push_back(b[bidx++]);
    }
    return ret;
}

vector<int> solve(int now){
    f[now][1]=c[now]-d[now];
    g[now][1]=c[now];
    cnt[now]=1;
    vector<int> ret;
    ret.push_back(c[now]);
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        vector<int> temp=solve(there);
        ret=merge(ret,temp);
        cnt[now]+=cnt[there];
    }
    ll sum=0;
    for(int i=0;i<ret.size();i++){
        sum+=ret[i];
        g[now][i+1]=sum;
    }
    int kk=1;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        memset(dp,0x3f,sizeof(dp));
        for(int j=0;j<=kk;j++)
            for(int k=0;k<=cnt[there];k++)
                dp[j+k]=min(dp[j+k],f[now][j]+f[there][k]);
        kk+=cnt[there];
        for(int j=0;j<=kk;j++)
            f[now][j]=dp[j];
    }
    for(int i=0;i<=ret.size();i++)
        f[now][i]=min(f[now][i],g[now][i]);
    return ret;
}
int main(){
    memset(f,0x3f,sizeof(f));
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&d[i]);
        if(i!=1){
            int x;
            scanf("%d",&x);
            adj[x].push_back(i);
        }
    }
    solve(1);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(f[1][i]<=b)
                ans=max(ans,i);
    printf("%d\n",ans);
    return 0;
}