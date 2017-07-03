#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int le[500005];
int ri[500005];
vector<int> adj[500005];
long long tree[1000005];
int cnt;
void dfs(int now){
    le[now]=cnt++;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        dfs(there);
    }
    ri[now]=cnt++;
}
void update(int idx,int val){
    idx++;
    while(idx<1000005){
        tree[idx]+=val;
        idx+=idx&(-idx);
    }
}
long long query(int idx){
    idx++;
    long long ret=0;
    while(idx){
        ret+=tree[idx];
        idx-=idx&(-idx);
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d",&arr[1]);
    for(int i=2;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[i]=a;
        adj[b].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        update(le[i],arr[i]);
        update(le[i]+1,-arr[i]);
        update(ri[i],arr[i]);
        update(ri[i]+1,-arr[i]);
    }
    for(int i=0;i<m;i++){
        char order[2];
        scanf("%s",order);
        if(order[0]=='p'){
            int a,b;
            scanf("%d%d",&a,&b);
            update(le[a]+1,b);
            update(ri[a],-b);
        }
        else{
            int a;
            scanf("%d",&a);
            printf("%lld\n",query(le[a]));
        }
    }
    return 0;
}