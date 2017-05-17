#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[63];
int solve(ll a,ll b,ll n){
    if(a>b)
        swap(a,b);
    if(a==b)
        return 1;
    if(a==0)
        return 0;
    return solve(a,b-r[n-1],n-1)+1;
}
int main(){
    int testcase;
    r[0]=1;
    for(int i=1;i<63;i++)
        r[i]=r[i-1]*2;
    scanf("%d",&testcase);
    while(testcase--){
        ll a,b,n;
        scanf("%lld%lld%lld",&n,&a,&b);
        printf("%d\n",solve(a,b,n));
    }
    return 0;
}