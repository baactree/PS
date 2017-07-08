#include <bits/stdc++.h>
using namespace std;
int n,k;
const int mod=10000;
int arr[100];
int cache[100][4][3];
int solve(int idx,int pre,int cnt){
    if(cnt==3)
        return 0;
    if(idx==n)
        return 1;
    int &ret=cache[idx][pre][cnt];
    if(ret!=-1)
        return ret;
    if(arr[idx]!=0){
        if(pre==arr[idx])
            return ret=solve(idx+1,arr[idx],cnt+1);
        return ret=solve(idx+1,arr[idx],1);
    }
    ret=0;
    for(int i=1;i<=3;i++){
        if(i==pre){
            ret+=solve(idx+1,i,cnt+1);
            ret%=mod;
        }
        else{
            ret+=solve(idx+1,i,1);
            ret%=mod;
        }
    }
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a-1]=b;
    }
    printf("%d\n",solve(0,0,1));
    return 0;
}