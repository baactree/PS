#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100005];
ll fi[100005];
const int mod=1e9+7;
ll mpow(ll a,ll b){
    if(b==0)
        return 1;
    ll temp=mpow(a,b/2);
    temp=(temp*temp)%mod;
    if(b&1)
        return (temp*a)%mod;
    return temp;
}
int n;
vector<ll> arr;
int main(){
    f[0]=1;
    for(int i=1;i<100005;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    fi[100004]=mpow(f[100004],mod-2);
    for(int i=100003;i>=0;i--)
        fi[i]=(fi[i+1]*(i+1))%mod;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll in;
        scanf("%lld",&in);
        arr.push_back(in);
    }
    int k=n-1;
    int p=k/4;
    if(p){
        n-=p*4;
        vector<ll> temp;
        for(int i=0;i<n;i++){
            ll now=0;
            for(int j=0;j<=p*2;j++){
                ll t=(((f[p*2]*fi[j])%mod)*fi[p*2-j])%mod;
                now+=(t*arr[i+j*2])%mod;
                now%=mod;
            }
            temp.push_back(now);
        }
        arr=temp;
    }
    bool flag=false;
    while(n>1){
        vector<ll> temp;
        for(int i=0;i<n-1;i++){
            ll now=0;
            if(flag){
                now=(arr[i]-arr[i+1]+mod)%mod;
            }
            else{
                now=(arr[i]+arr[i+1])%mod;
            }
            temp.push_back(now);
            flag=!flag;
        }
        arr=temp;
        n--;
    }
    printf("%lld\n",arr[0]);
    return 0;
}