#include <bits/stdc++.h>
using namespace std;
struct Node{
    int a,b,w;
};
int n;
Node arr[100005];
bool pick[20];
bool disj(int a,int b){
    if(arr[a].b<arr[b].a||arr[b].b<arr[a].a)
        return false;
    return true;
}
int solve(int idx,int w){
    if(idx==n){
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!pick[i]){
                bool t=false;
                for(int j=0;j<n;j++){
                    if(disj(i,j)&&pick[j])
                        t=true;
                }
                if(!t)
                    flag=true;
            }
        }
        if(flag)
            return 0x3f3f3f3f;
        return w;
    }
    int ret=0x3f3f3f3f;
    pick[idx]=true;
    ret=min(ret,solve(idx+1,w+arr[idx].w));
    pick[idx]=false;
    ret=min(ret,solve(idx+1,w));
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].w);
        int ans=0;
        if(n<=15){
            ans=solve(0,0);
        }
        printf("Case #%d\n%d\n",tc,ans);
    }
    return 0;
}