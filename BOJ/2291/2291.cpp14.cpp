#include "bits/stdc++.h"
using namespace std;
int cache[11][221][221];
int N,M,K;
int solve(int n,int m,int pre){
    if(n==0){
        return m==0;
    }
    int &ret=cache[n][m][pre];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=pre;i<=m;i++)
        ret+=solve(n-1,m-i,i);
    return ret;
}
string get_ans(int n,int m,int pre,int k){
    if(n==0)
        return "";
    for(int i=pre;i<=m;i++){
        int cnt=solve(n-1,m-i,i);
        if(cnt<=k)
            k-=cnt;
        else
            return to_string(i)+" "+get_ans(n-1,m-i,i,k);
    }
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d%d%d",&N,&M,&K);
    solve(N,M,1);
    cout<<get_ans(N,M,1,K-1)<<endl;
    return 0;
}