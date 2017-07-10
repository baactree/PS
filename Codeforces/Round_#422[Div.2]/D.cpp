#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int t,l,r;
int d[5000005];
ll dp[5000005];
ll f[5000005];
int main(){
    scanf("%d%d%d",&t,&l,&r);
    f[0]=1;
    for(int i=1;i<5000005;i++)
        f[i]=(f[i-1]*t)%mod;
    for(ll i=2;i*i<5000005;i++){
        if(d[i]!=0)
            continue;
        for(ll j=i*i;j<5000005;j+=i)
            if(d[j]==0)
                d[j]=i;
    }
    for(ll i=2;i<5000005;i++){
        if(d[i]==0)
            dp[i]=(i*(i-1)/2)%mod;
        else{
            int k=i/d[i];
            dp[i]=(dp[k]+k*dp[d[i]])%mod;
        }
    }
    ll ans=0;
    for(int i=l,k=0;i<=r;i++,k++){
        ans+=(f[k]*dp[i])%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}