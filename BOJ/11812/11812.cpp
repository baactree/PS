#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k;
int q;
ll depth(ll x){
    ll ret=0;
    while(x){
        x=(x+k-1)/k-1;
        ret++;
    }
    return ret;
}
int main(){
    scanf("%lld%d%d",&n,&k,&q);
    while(q--){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        x--;
        y--;
        if(k==1){
            printf("%lld\n",abs(x-y));
            continue;
        }
        ll dx=depth(x);
        ll dy=depth(y);
        if(dx<dy){
            swap(dx,dy);
            swap(x,y);
        }
        ll dist=0;
        while(dx!=dy){
            x=(x+k-1)/k-1;
            dx--;
            dist++;
        }
        while(x!=y){
            x=(x+k-1)/k-1;
            y=(y+k-1)/k-1;
            dist+=2;
        }
        printf("%lld\n",dist);
    }
}