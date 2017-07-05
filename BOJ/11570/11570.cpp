#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2000];
int cache[2005][2005][2];
int solve(int idx,int pre,int mode){
    if(idx==n)
        return 0;
    int &ret=cache[idx][pre+1][mode];
    if(ret!=-1)
        return ret;
    //이전에 누른사람이 없음
    if(idx==0){
        ret=solve(idx+1,-1,1);
        ret=min(ret,solve(idx+1,-1,0));
        return ret;
    }
    //이전에 누른게 상덕이꺼 즉 pre가 희원이
    if(mode){
        ret=solve(idx+1,pre,1)+abs(arr[idx]-arr[idx-1]);
        ret=min(ret,solve(idx+1,idx-1,0)+(pre==-1?0:abs(arr[pre]-arr[idx])));
        return ret;
    }
    //이전에 누른게 희원이꺼 즉 pre가 상덕이
    ret=solve(idx+1,idx-1,1)+(pre==-1?0:abs(arr[pre]-arr[idx]));
    ret=min(ret,solve(idx+1,pre,0)+abs(arr[idx]-arr[idx-1]));
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve(0,-1,0));
    return 0;
}