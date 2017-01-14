#include "bits/stdc++.h"
using namespace std;
int N;
int cache[16][1<<16];
int mat[16][16];
int solve(int now,int state){
    if(state==(1<<N)-1){
        if(mat[now][0])
            return mat[now][0];
        return 0x3f3f3f3f;
    }
    int &ret=cache[now][state];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    for(int i=0;i<N;i++){
        if((state&(1<<i))||!mat[now][i])
            continue;
        ret=min(ret,solve(i,state|(1<<i))+mat[now][i]);
    }
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&mat[i][j]);
    printf("%d\n",solve(0,1));
    return 0;
}