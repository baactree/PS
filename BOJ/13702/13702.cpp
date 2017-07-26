#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[10000];
typedef long long ll;
bool possi(ll x){
    int ret=0;
    for(int i=0;i<n;i++)
        ret+=arr[i]/x;
    return ret>=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    ll le,ri,mid,ans;
    le=1;ri=(1ll<<31)-1;
    ans=-1;
    while(le<=ri){
        mid=(le+ri)/2;
        if(possi(mid)){
            ans=mid;
            le=mid+1;
        }
        else
            ri=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}