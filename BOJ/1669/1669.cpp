#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
int main(){
    scanf("%lld%lld",&x,&y);
    y-=x;
    ll ans=0;
    while(true){
        ll now=0;
        if(ans&1){
            ll p=(ans+1)/2;
            now=p*(p+1)-p;
        }
        else{
            ll p=ans/2;
            now=p*(p+1);
        }
        if(y<=now){
            printf("%lld\n",ans);
            return 0;
        }
        ans++;
    }
    return 0;
}