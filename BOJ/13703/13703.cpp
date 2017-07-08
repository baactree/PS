#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,n;
ll cache[64][64];
ll solve(int idx,int r){
    if(r==0)
        return 0;
    if(idx==n)
        return 1;
    ll &ret=cache[idx][r];
    if(ret!=-1)
        return ret;
    ret=solve(idx+1,r+1);
    ret+=solve(idx+1,r-1);
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d%d",&k,&n);
    printf("%lld\n",solve(0,k));
    return 0;
}