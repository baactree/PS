#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map<pair<int,int> ,int> mp;
const int mod=1e9+7;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
pair<int,int> trans(int a,int b){
    if(a==0)
        return make_pair(0,1);
    if(b==0)
        return make_pair(1,0);
    int g=gcd(a,b);
    return make_pair(a/g,b/g);
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        mp[trans(a,b)]++;
    }
    ll ans=n*(n-1)*(n-2)/6;
    for(auto it=mp.begin();it!=mp.end();it++){
        ll cnt=it->second;
        ans-=cnt*(cnt-1)*(cnt-2)/6;
        ans-=cnt*(cnt-1)/2*(n-cnt);
    }
    printf("%lld\n",ans%mod);
    return 0;
}