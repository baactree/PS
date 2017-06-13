#include <bits/stdc++.h>
using namespace std;
int tree[4000000];
int n,m;
int sz;
void update(int idx,int val){
    idx+=sz;
    while(idx){
        tree[idx]=max(tree[idx],val);
        idx/=2;
    }
}
int query(int a,int b){
    a+=sz;
    b+=sz;
    int ret=0;
    while(a<=b){
        if(a&1){
            ret=max(ret,tree[a]);
            a++;
        }
        if(!(b&1)){
            ret=max(ret,tree[b]);
            b--;
        }
        a/=2;
        b/=2;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    sz=1;
    while(sz<n)
        sz*=2;
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        update(i,in);
    }
    for(int i=m-1;i+m<=n;i++){
        printf("%d ",query(i-m+1,i+m-1));
    }
    printf("\n");
    return 0;
}