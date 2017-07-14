#include <bits/stdc++.h>
using namespace std;
int n,s,m;
int arr[100000];
int calc(int x){
    int ret=0;
    for(int i=0;i<m;i++){
        ret+=(x/arr[i]+1);
        ret=min(ret,0x3f3f3f3f);
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&s);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&arr[i]);
    int le,ri,mid,t;
    le=0;
    ri=0x3f3f3f3f;
    t=0;
    while(le<=ri){
        int mid=(le+ri)/2;
        if(n-s<=calc(mid)){
            t=mid;
            ri=mid-1;
        }
        else
            le=mid+1;
    }
    int ans=-1;
    int k=calc(t)-(n-s);
    for(int i=m-1;i>=0;i--){
        if(t%arr[i]==0){
            ans=i+1;
            if(k==0)
                break;
            k--;
        }
    }
    printf("%d\n",ans);
    return 0;
}