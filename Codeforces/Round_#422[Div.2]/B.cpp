#include <bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
vector<int> calc(string k){
    vector<int> ret;
    for(int i=0;i<k.size();i++)
        if(s[i]!=k[i])
            ret.push_back(i+1);
    return ret;
}
int main(){
    cin>>n>>m>>s>>t;
    vector<int> ans(n+1);
    for(int i=0;i+s.size()<=t.size();i++){
        vector<int> temp=calc(string(t.begin()+i,t.begin()+i+s.size()));
        if(ans.size()>temp.size())
            ans=temp;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}