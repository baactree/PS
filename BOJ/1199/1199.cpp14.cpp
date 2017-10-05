#include "bits/stdc++.h"
using namespace std;
int mat[1000][1000];
int cnt[1000];
int N,M;
vector<int> ans;
void dfs(int now,vector<int> &circuit){
    for(int i=0;i<N;i++){
        if(mat[now][i]>0){
            mat[now][i]--;
            mat[i][now]--;
            dfs(i,circuit);
        }
    }
    circuit.push_back(now);
}
vector<int> make_Circuit(){
    vector<int> ret;
    for(int i=0;i<N;i++){
        if(cnt[i]&1){
            dfs(i,ret);
            return ret;
        }
    }
    for(int i=0;i<N;i++){
        if(cnt[i]>0){
            dfs(i,ret);
            return ret;
        }
    }
    return ret;
}
bool check(){
    int odd=0;
    for(int i=0;i<N;i++)
        if(cnt[i]&1)
         odd++;
   return odd==0||odd==2;
}
void solve(){
    if(!check())
        return;
    ans=make_Circuit();
    if(ans.size()!=M+1){
        ans.clear();
        return;
    }
}
int main(){
    scanf("%d",&N);
    assert(N>=1&&N<=1000);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
            assert(mat[i][j]>=0&&mat[i][j]<=10);
            if(i==j&&mat[i][j])
                assert(false);
            cnt[i]+=mat[i][j];
            M+=mat[i][j];
        }
    M/=2;
    solve();
    if(ans.size()==0||M==0)
        printf("-1\n");
    else{
        for(auto i:ans)
            printf("%d ",i+1);
    }
    return 0;
}