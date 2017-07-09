#include <bits/stdc++.h>
using namespace std;
string st;
string fi;
int n;
int cache[10005][10];
int solve(int idx,int rot){
    if(idx==n)
        return 0;
    int &ret=cache[idx][rot];
    if(ret!=-1)
        return ret;
    int now=(st[idx]+rot-'0')%10;
    int l=(fi[idx]-'0'-now+10)%10;
    ret=solve(idx+1,(rot+l)%10)+l;
    int r=(now-(fi[idx]-'0')+10)%10;
    ret=min(ret,solve(idx+1,rot)+r);
    return ret;
}
void get_ans(int idx,int rot,vector<int> &vec){
    if(idx==n)
        return;
    int now=(st[idx]+rot-'0')%10;
    int l=(fi[idx]-'0'-now+10)%10;
    int a=solve(idx+1,(rot+l)%10)+l;
    int r=(now-(fi[idx]-'0')+10)%10;
    int b=solve(idx+1,rot)+r;
    if(a<b){
        vec.push_back(l);
        return get_ans(idx+1,(rot+l)%10,vec);
    }
    vec.push_back(-r);
    return get_ans(idx+1,rot,vec);
}
int main(){
    memset(cache,-1,sizeof(cache));
    cin>>n>>st>>fi;
    printf("%d\n",solve(0,0));
    vector<int> ans;
    get_ans(0,0,ans);
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",i+1,ans[i]);
    return 0;
}