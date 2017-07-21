#include <bits/stdc++.h>
using namespace std;
int cache[1000005];
int p[1000005];
int n,m,k;
bool possi[10];
const int inf=0x3f3f3f3f;
int check(int x){
    int &ret=p[x];
    if(ret!=-1)
        return ret;
    ret=1;
    while(x){
        if(!possi[x%10])
            return ret=0;
        x/=10;
    }
    return ret;
}
int solve(int x){
    if(check(x))
        return 0;
    int &ret=cache[x];
    if(ret!=-1)
        return ret;
    ret=inf;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int j=x/i;
            ret=min(ret,solve(i)+solve(j)+1);
        }
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        memset(cache,-1,sizeof(cache));
        memset(possi,0,sizeof(possi));
        memset(p,-1,sizeof(p));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            possi[x]=true;
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d",&k);
            assert(k!=0);
            int ans=solve(k);
            printf("%d\n",ans==inf?-1:ans);
        }
    }
    return 0;
}