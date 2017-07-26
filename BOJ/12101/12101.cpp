#include <bits/stdc++.h>
using namespace std;
int cache[20];
int solve(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    int &ret=cache[n];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=1;i<=3;i++)
        ret+=solve(n-i);
    return ret;
}
vector<int> ans;
void get_ans(int n,int k){
    if(n<=0)
        return;
    for(int i=1;i<=3;i++){
        int temp=solve(n-i);
        if(k<=temp){
            ans.push_back(i);
            get_ans(n-i,k);
            return;
        }
        k-=temp;
    }
}
int main(){
    int n,k;
    memset(cache,-1,sizeof(cache));
    scanf("%d%d",&n,&k);
    solve(n);
    
    get_ans(n,k);
    if(ans.empty())
        return !printf("-1\n");
    for(int i=0;i<ans.size();i++)
        printf("%d%s",ans[i],(i+1==ans.size()?"\n":"+"));
    return 0;
}