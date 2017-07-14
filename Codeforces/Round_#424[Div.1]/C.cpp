#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
int arr[100];
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        k+=arr[i];
    }
    vector<ll> seg;
    for(int i=0;i<n;i++){
        vector<ll> vec;
        int t=sqrt(arr[i])+1;
        for(int j=1;j<=t;j++){
            vec.push_back((arr[i]+j-1)/j);
            vec.push_back(j);
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        reverse(vec.begin(),vec.end());
        for(int j=0;j<vec.size();j++)
            seg.push_back((arr[i]+vec[j]-1)/vec[j]);
    }
    seg.push_back(1e12);
    sort(seg.begin(),seg.end());
    seg.erase(unique(seg.begin(),seg.end()),seg.end());
    ll ans=0;
    for(int i=0;i+1<seg.size();i++){
        ll le,ri,mid;
        le=seg[i];
        ri=seg[i+1]-1;
        ll sum=0;
        for(int j=0;j<n;j++)
            sum+=(arr[j]+seg[i]-1)/seg[i];
        while(le<=ri){
            mid=(le+ri)/2;
            if(mid*sum<=k){
                le=mid+1;
                ans=max(ans,mid);
            }
            else
                ri=mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}