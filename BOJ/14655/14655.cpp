#include <bits/stdc++.h>
using namespace std;
int arr[10020];
int n;
int cache[10020][4];
int calc(int state,int mode,int idx){
    while(state){
        if(state&1)
            mode=1-mode;
        state>>=1;
    }
    if(mode)
        return -arr[idx];
    return arr[idx];
}
int solve1(int idx,int state){
    if(idx==n+2)
        return 0;
    int &ret=cache[idx][state];
    if(ret!=-1)
        return ret;
    ret=solve1(idx+1,state>>1)+calc(state,0,idx);
    ret=max(ret,solve1(idx+1,(state>>1)+2)+calc(state,1,idx));
    return ret;
}
int solve2(int idx,int state){
    if(idx==n+2)
        return 0;
    int &ret=cache[idx][state];
    if(ret!=-1)
        return ret;
    ret=solve2(idx+1,state>>1)+calc(state,0,idx);
    ret=min(ret,solve2(idx+1,(state>>1)+2)+calc(state,1,idx));
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i+2]);
    memset(cache,-1,sizeof(cache));
    int a=solve1(0,0);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i+2]);
    memset(cache,-1,sizeof(cache));
    int b=solve2(0,0);
    printf("%d\n",a-b);
    return 0;
}