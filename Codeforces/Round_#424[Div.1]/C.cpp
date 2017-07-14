#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
int arr[100];
ll sum;
bool possi(ll x){
    ll s=0;
    for(int i=0;i<n;i++)
        s+=(arr[i]+x-1)/x;
    //cout<<s<<" "<<x<<endl;
    return s*x<=k+sum;
}
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    ll ans=0;
    for(ll i=max(1.0,k/3-1e6);i<k/3+1e6;i++){
        if(possi(i))
            ans=max(ans,i);
    }
    printf("%lld\n",ans);
    return 0;
}