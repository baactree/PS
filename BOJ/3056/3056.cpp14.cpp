#include "bits/stdc++.h"
using namespace std;
double cache[1<<20];
int mat[20][20];
int N;
double solve(int idx,int state){
    if(idx==N)
        return 1;
    double &ret=cache[state];
    if(ret>=-0.5)
        return ret;
    ret=0;
    for(int i=0;i<N;i++){
        if((state&(1<<i)))
            continue;
        ret=max(ret,solve(idx+1,state|(1<<i))*mat[idx][i]/100.0);
    }
    return ret;
}
int main(){
    for(int i=0;i<(1<<20);i++)
        cache[i]=-1.0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%d",&mat[i][j]);
    }
    printf("%.10lf\n",solve(0,0)*100);
    return 0;
}