#include <bits/stdc++.h>
using namespace std;
int tree[70000];
void update(int idx,int val){
    idx++;
    while(idx<70000){
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    idx++;
    int ret=0;
    while(idx){
        ret+=tree[idx];
        idx-=idx&(-idx);
    }
    return ret;
}
int n,k;
int arr[300000];
int main(){
    scanf("%d%d",&n,&k);
    long long ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        update(arr[i],1);
        if(i>=k-1){
            int le,ri,mid,idx;
            le=0;
            ri=70000;
            idx=0;
            while(le<=ri){
                mid=(le+ri)/2;
                if(query(mid)>=(k+1)/2){
                    idx=mid;
                    ri=mid-1;
                }
                else
                    le=mid+1;
            }
            ans+=idx;
            update(arr[i-(k-1)],-1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}