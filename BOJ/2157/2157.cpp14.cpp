#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dp[302][302],n,m,k;
vector<vector<pair<int,int> > > adj;
int go(int pos,int count){
    int &ans=dp[pos][count];
    if(count==0){
        if(pos<n)return ans=-1e9;
        else return 0;
    }
    if(pos==n){
        if(count>=0)return 0;
        else return ans=-1e9;
    }
    if(ans!=-1)return ans;
    ans=-1e9;
    for(auto there :adj[pos]){
        ans=max(ans,there.second+go(there.first,count-1));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    adj.resize(301);
    for(int i=0;i<k;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        if(from>to)continue;
        adj[from].push_back(make_pair(to,cost));
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    int ret=go(1,m-1);
    if(ret<-1e8)cout<<0;
    else cout<<ret;
    return 0;
}