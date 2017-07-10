#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x,t,k;
};
int cache[505][505];
int mat[505][505];
Node arr[500];
int n;
const int mod=1000;
int solve(int st,int fi){
    int &ret=cache[st][fi];
    if(ret!=-1)
        return ret;
    ret=0;
    if(st!=n-1&&fi!=n-1)
        if(mat[st][n-1]&&mat[n-1][fi])
            ret++;
    for(int i=max(st,fi)+1;i<n;i++){
        if(mat[st][i]){
            ret+=solve(i,fi);
            ret%=mod;
        }
        if(mat[i][fi]){
            ret+=solve(st,i);
            ret%=mod;
        }
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].x,&arr[i].t,&arr[i].k);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            //i->j
            if(j<i&&arr[j].k==0)
                continue;
            if(abs(arr[i].x-arr[j].x)>arr[i].t)
                continue;
            mat[i][j]=true;
        }
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve(0,0));
    return 0;
}