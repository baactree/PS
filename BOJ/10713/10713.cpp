#include <bits/stdc++.h>
using namespace std;
int n,m;
int tree[100005];
int arr[100005];
int a[100005],b[100005],c[100005];
void update(int idx,int val){
    while(idx<100005){
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int ret=0;
    while(idx){
        ret+=tree[idx];
        idx-=idx&(-idx);
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=0;i<m-1;i++){
        int u=arr[i];
        int v=arr[i+1];
        if(u>v)
            swap(u,v);
        update(u,1);
        update(v,-1);
    }
    long long ans=0;
    for(int i=1;i<n;i++){
        long long cnt=query(i);
        ans+=min(cnt*a[i],cnt*b[i]+c[i]);
    }
    printf("%lld\n",ans);
    return 0;
}