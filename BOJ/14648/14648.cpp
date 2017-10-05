#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tree[4000];
int sz;
void update(int idx,int val){
    idx+=sz;
    while(idx){
        tree[idx]+=val;
        idx/=2;
    }
}
ll query(int a,int b){
    a+=sz;
    b+=sz;
    ll ret=0;
    while(a<=b){
        if(a&1)
            ret+=tree[a++];
        if(!(b&1))
            ret+=tree[b--];
        a/=2;
        b/=2;
    }
    return ret;
}
int n,q;
int arr[1000];
int main(){
    scanf("%d%d",&n,&q);
    sz=1;
    while(sz<n)
        sz*=2;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        update(i,arr[i]);
    }
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            printf("%lld\n",query(a,b));
            update(a,arr[b]-arr[a]);
            update(b,arr[a]-arr[b]);
            swap(arr[a],arr[b]);
        }
        else{
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a--;b--;c--;d--;
            printf("%lld\n",query(a,b)-query(c,d));
        }
    }
    return 0;
}