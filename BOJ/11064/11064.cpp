#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
vector<pair<int,int> > adj[40005];
ll depth[40005];
ll goal[40005];
ll ans[40005];
ll dp[40005];
ll dfs1(int now,int par){
    depth[now]=0;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].first;
        int weight=adj[now][i].second;
        if(there==par)
            continue;
        depth[now]=max(depth[now],dfs1(there,now)+weight);
    }
    return depth[now];
}
void dfs2(int now,int par,ll max_depth){
    goal[now]=max_depth;
    vector<pair<ll,int> >vec;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].first;
        int weight=adj[now][i].second;
        if(there==par)
            continue;
        vec.push_back({depth[there]+weight,there});
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    if(vec.size()>=2){
        if(vec[0].first>d/2&&vec[1].first>d/2){
            ll p=d/2;
            goal[now]=min(goal[now],p);
            for(int i=0;i<vec.size();i++)
                dfs2(vec[i].second,now,goal[now]);
                
        }
        // 가장 깊은 서브트리와 두번째로 깊은 서브트리의 깊이 합이
        // d를 초과할때 어느 서브트리의 깊이를 조정하는게 이득인가?

        // 딱히 뭘 조정해도 상관이 없다면 가장 깊은 서브트리를 조정하는게 좋다.
        else if(vec[0].first>d/2){
            ll k=max(vec[0].first+vec[1].first-d,0ll);
            goal[now]=min(goal[now],vec[0].first-k);
            for(int i=0;i<vec.size();i++)
                dfs2(vec[i].second,now,goal[now]);
        }
        else{
            for(int i=0;i<vec.size();i++)
                dfs2(vec[i].second,now,max_depth);
        }
    }
    else if(vec.size()==1)
        dfs2(vec[0].second,now,max_depth);
}
void dfs3(int now,int par){
    ans[now]=dp[now]=0;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].first;
        if(there==par)
            continue;
        dfs3(there,now);
    }
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i].first;
        int weight=adj[now][i].second;
        if(there==par)
            continue;
        ll sub_depth=dp[there]+weight;
        ll k=max(0ll,sub_depth-goal[now]);
        ans[now]+=k;
        dp[now]=max(dp[now],min(sub_depth,goal[now]));
        ans[now]+=ans[there];
    }
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        for(int i=0;i<40005;i++)
            adj[i].clear();
        scanf("%d%d",&n,&d);
        d*=2;
        for(int i=0;i<n-1;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back({b,2*c});
            adj[b].push_back({a,2*c});
        }
        dfs1(1,0);
        dfs2(1,0,d);
        dfs3(1,0);
        ll answer=ans[1];
        printf("%lld",answer/2);
        if(answer&1)
            printf(".5\n");
        else printf(".0\n");
    }
    return 0;
}