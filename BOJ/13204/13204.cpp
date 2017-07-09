#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        ll p,q;
        scanf("%lld.%lld",&p,&q);
        ll a=p*1000+q;
        ll le=a*10-5;
        ll ri=a*10+5;
        ll b=100000;
        ll ans=b;
        while(b){
            ll k=a*1000000/b;
            while(k>=le){
                a--;
                k=a*1000000/b;
            }
            while(k<ri){
                if(k>=le){
                    ll g=gcd(a,b);
                    ans=min(ans,b/g);
                    a/=g;
                    b/=g;
                }
                a++;
                k=a*1000000/b;
            }
            b--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}