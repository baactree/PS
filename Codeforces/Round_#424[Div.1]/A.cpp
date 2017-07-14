#include <bits/stdc++.h>
using namespace std;
int n,k,p;
int a[1000];
int b[2000];
typedef long long ll;
bool possi(ll x){
    int nidx,kidx;
    nidx=kidx=0;
    int cnt=0;
    for(nidx=0;nidx<n&&kidx<k;nidx++,kidx++){
        while(kidx<k&&abs(a[nidx]-b[kidx])+abs(b[kidx]-p)>x)
            kidx++;
        if(kidx<k&&abs(a[nidx]-b[kidx])+abs(b[kidx]-p)<=x)
            cnt++;
    }
    return cnt==n;
}
int main(){
    scanf("%d%d%d",&n,&k,&p);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+k);
    ll le,ri,mid,ans;
    le=0;
    ri=2e9;
 //  possi(30);
    while(le<=ri){
        mid=(le+ri)/2;
        if(possi(mid)){
            ans=mid;
            ri=mid-1;
        }
        else
            le=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}