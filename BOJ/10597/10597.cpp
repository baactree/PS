#include <bits/stdc++.h>
using namespace std;
string str;
int n;
bool used[51];
vector<int> ans;
void solve(int idx){
    if(idx==str.size()){
        for(int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        }
        exit(0);
    }
    if(str[idx]-'0'>=1&&str[idx]-'0'<10&&!used[str[idx]-'0']){
        used[str[idx]-'0']=true;
        ans.push_back(str[idx]-'0');
        solve(idx+1);
        used[str[idx]-'0']=false;
        ans.pop_back();
    }
    if(idx+1<str.size()){
    int now=(str[idx]-'0')*10+str[idx+1]-'0';
    if(now>=1&&now<=n&&!used[now]){
        used[now]=true;
        ans.push_back(now);
        solve(idx+2);
        used[now]=false;
        ans.pop_back();
    }
    }
}
int main(){
    cin>>str;
    if(str.size()<10)
        n=str.size();
    else{
        int k=str.size();
        k-=9;
        k/=2;
        n=k+9;
    }
    solve(0);
    return 0;
}