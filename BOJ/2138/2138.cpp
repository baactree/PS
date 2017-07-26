#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005];
int cache[100000][1<<3];
const int inf=0x3f3f3f3f;
int solve(int idx,int state){
    if(idx==n-1){
        int g=(b[n-2])+(b[n-1]<<1);
        if(state==g)
            return 0;
        if((state^3)==g)
            return 1;
        return inf;
    }
    int &ret=cache[idx][state];
    if(ret!=-1)
        return ret;
    if(idx==0){
        int nextstate=(state>>1)+(a[idx+2]<<2);
        ret=solve(idx+1,nextstate);
        ret=min(ret,solve(idx+1,nextstate^3)+1);
        return ret;
    }
    int pre=state&1;
    int nextstate=(state>>1)+(a[idx+2]<<2);
    if(pre==b[idx-1])
        ret=solve(idx+1,nextstate);
    else
        ret=solve(idx+1,nextstate^3)+1;
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%1d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%1d",&b[i]);
    int ans=solve(0,(a[0]<<1)+(a[1]<<2));
    printf("%d\n",ans==inf?-1:ans);
    return 0;
}