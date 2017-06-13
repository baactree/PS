#include <bits/stdc++.h>
using namespace std;
long long ans[100000];
int n;
pair<int,int> arr[100000];
int tree[100005];
void update(int idx,int val){
    idx+=2;
    while(idx<100005){
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int ret=0;
    idx+=2;
    while(idx){
        ret+=tree[idx];
        idx-=idx&(-idx);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i].first);
        arr[i].second=i;
    }
    sort(arr,arr+n);
    int pre=1;
    int pidx=-1;
    long long t=0;
    for(int i=0;i<n;i++){
        int now=arr[i].first;
        int idx=arr[i].second;
        if(now==pre){
            long long k=query(idx)-query(pidx);
            t+=idx-pidx-k;
            ans[idx]=t;
            update(idx,1);
            pre=now;
            pidx=idx;
        }
        else{
            long long k=query(n-1)-query(pidx);
            t+=n-1-pidx-k;
            k=query(n-1);
            t+=(n-k)*(now-pre-1);
            k=query(idx);
            t+=idx+1-k;
            ans[idx]=t;
            update(idx,1);
            pre=now;
            pidx=idx;
        }
    }
    for(int i=0;i<n;i++)
        printf("%lld\n",ans[i]);
    return 0;
}