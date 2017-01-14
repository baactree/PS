#include "bits/stdc++.h"
using namespace std;
int A,B;
double cache[19][19][19];
bool prime[19]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
double solve(int idx,int a,int b){
    if(idx==18){
        if(prime[a]||prime[b])
            return 1;
        return 0;
    }
    double &ret=cache[idx][a][b];
    if(ret>=-0.5)
        return ret;
    ret=0;
    ret+=solve(idx+1,a,b)*(100-A)*(100-B)/10000.0;
    ret+=solve(idx+1,a+1,b)*(A)*(100-B)/10000.0;
    ret+=solve(idx+1,a,b+1)*(100-A)*(B)/10000.0;
    ret+=solve(idx+1,a+1,b+1)*A*B/10000.0;
    return ret;
}
int main(){
    for(int i=0;i<19;i++)
        for(int j=0;j<19;j++)
        for(int k=0;k<19;k++)
            cache[i][j][k]=-1.0;
    scanf("%d%d",&A,&B);
    printf("%.10lf\n",solve(0,0,0));
    return 0;
}