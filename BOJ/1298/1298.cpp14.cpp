#include "bits/stdc++.h"
using namespace std;
int N,M;
vector<int> edge[101];
bool trip[101];
int matched[101];
bool dfs(int now){
    if(trip[now])
        return false;
    trip[now]=true;
    for(int i=0;i<edge[now].size();i++){
        int there=edge[now][i];
        if(matched[there]==-1||dfs(matched[there])){
            matched[there]=now;
            return true;
        }
    }
    return false;
}
int main(){
    memset(matched,-1,sizeof(matched));
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
    }
    int cnt=0;
    for(int i=1;i<=N;i++){
        memset(trip,0,sizeof(trip));
        if(dfs(i))
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}