#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int> > adj[1001];
int dp[1001];
void solve(int now,int par){
    int cnt=0;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].first;
        if(there==par)
            continue;
        solve(there,now);
        cnt++;
    }
    if(cnt==0){
        dp[now]=0x3f3f3f3f;
        return;
    }
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].first;
        int cost=adj[now][i].second;
        if(there==par)
            continue;
        dp[now]+=min(cost,dp[there]);
    }
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            adj[i].clear();
        for(int i=0;i<m;i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            adj[a].push_back(make_pair(b,d));
            adj[b].push_back(make_pair(a,d));
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        solve(1,0);
        printf("%d\n",dp[1]);
    }
    return 0;
}