#include <bits/stdc++.h>
using namespace std;
int n,k;
int tree[100005];
void update(int idx,int val){
    idx++;
    while(idx<100005){
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
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        if(in==1){
            update(i,1);
            update(i+1,-1);
        }
    }
    int ans=0;
    for(int i=0;i+k<=n;i++){
        int now=query(i);
        if(now&1){
            ans++;
            update(i,1);
            update(i+k,-1);
        }
    }
    bool flag=false;
    for(int i=n-k+1;i<n;i++)
        if(query(i)&1)
            flag=true;
    if(flag)
        printf("Insomnia\n");
    else
        printf("%d\n",ans);
    return 0;
}