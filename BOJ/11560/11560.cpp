#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,n;
ll cache[25][250];
ll solve(int idx,int p){
    if(p<0)
        return 0;
    if(idx==0)
        return p==0;
    ll &ret=cache[idx][p];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0;i<=idx;i++)
        ret+=solve(idx-1,p-i);
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d%d",&k,&n);
        printf("%lld\n",solve(k,n));
    }
    return 0;
}