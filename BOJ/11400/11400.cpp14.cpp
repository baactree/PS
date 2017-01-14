#include "bits/stdc++.h"
using namespace std;
vector<int> edge[100001];

int discovered[100001];

vector<pair<int,int> >  ans;
int N,M;
int dis_cnt=0;
int dfs(int now,int par){
    discovered[now]=dis_cnt++;
    int ret=discovered[now];
    for(int i=0;i<edge[now].size();i++){
        int there=edge[now][i];
        if(there==par)
            continue;
        if(discovered[there]==-1){
            int subtree=dfs(there,now);
            if(subtree>discovered[now])
                ans.push_back({now,there});
            ret=min(ret,subtree);
        }
        else
            ret=min(ret,discovered[there]);
    }
    return ret;
}
int main(){
    memset(discovered,-1,sizeof(discovered));
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
        if(discovered[i]==-1)
            dfs(i,0);
    for(int i=0;i<ans.size();i++){
        if(ans[i].first>ans[i].second)
            swap(ans[i].first,ans[i].second);
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    
    for(int i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
    
}