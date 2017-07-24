#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > ans;
void solve(){
    if(n&1){
        vector<int> v({1,2,3});
        ans.push_back(v);
        ans.push_back(v);
        for(int i=5;i<=n;i+=2){
            int s=i-1;
            int t=i;
            for(int j=1;j<i-2;j++)
                ans.push_back(vector<int>({s,j,t,j+1}));
            ans.push_back(vector<int>({s,1,t}));
            ans.push_back(vector<int>({s,i-2,t}));
        }
    }
    else{
        ans.push_back(vector<int>({1,2,3}));
        ans.push_back(vector<int>({1,2,4}));
        ans.push_back(vector<int>({3,4,1}));
        ans.push_back(vector<int>({3,4,2}));
        for(int i=6;i<=n;i+=2){
            int s=i-1;
            int t=i;
            for(int j=1;j<i-2;j++)
                ans.push_back(vector<int>({s,j,t,j+1}));
            ans.push_back(vector<int>({s,1,t}));
            ans.push_back(vector<int>({s,i-2,t}));
        }
    }
}
int main(){
    scanf("%d",&n);
    solve();
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d",ans[i].size());
        for(auto x:ans[i])
            printf(" %d",x);
        printf("\n");
    }
    return 0;
}