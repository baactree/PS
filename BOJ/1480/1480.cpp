#include <bits/stdc++.h>
using namespace std;
int n,m,c;
int arr[13];
int cache[1<<13][11][21];
const int inf=0x3f3f3f3f;
int solve(int cn,int cm,int v,int state){
    if(v>c)
        return -inf;
    if(cn==0||cm==0)
        return 0;
    int &ret=cache[state][cm][v];
    if(ret!=-1)
        return ret;
    ret=solve(cn,cm-1,0,state);
    for(int i=0;i<n;i++){
        if(!((1<<i)&state))
            ret=max(ret,solve(cn-1,cm,v+arr[i],state|(1<<i))+1);
    }
    return ret;
}
int main(){
    scanf("%d%d%d",&n,&m,&c);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve(n,m,0,0));
    return 0;
}