#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cache[21][21][2];
ll solve(int lo,int hi,int mode){
    if(lo==0&&hi==0)
        return 1;
    ll &ret=cache[lo][hi][mode];
    if(ret!=-1)
        return ret;
    ret=0;
    if(mode){
        for(int i=0;i<lo;i++)
            ret+=solve(i,lo-1-i+hi,1-mode);
    }
    else{
        for(int i=0;i<hi;i++)
            ret+=solve(lo+i,hi-1-i,1-mode);
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        if(n==1){
            printf("1\n");
            continue;
        }
        memset(cache,-1,sizeof(cache));
        long long ans=0;
        for(int i=0;i<n;i++)
            ans+=solve(i,n-1-i,0)+solve(i,n-1-i,1);
        printf("%lld\n",ans);
    }
    return 0;
}