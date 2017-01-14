#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int N,R,G,B;
ll cache[11][101][101][101];
ll fact[11];
ll solve(int idx,int r,int g,int b){
    if(r<0||g<0||b<0)
        return 0;
    if(idx==N+1)
        return 1;
    ll &ret=cache[idx][r][g][b];
    if(ret!=-1)
        return ret;
    ret=0;
    if(idx%2==0){
        int pick=idx/2;
        ll multi=fact[idx]/fact[pick]/fact[pick];
        //rg
        ret+=solve(idx+1,r-pick,g-pick,b)*multi;
        //rb
        ret+=solve(idx+1,r-pick,g,b-pick)*multi;
        //bc
        ret+=solve(idx+1,r,g-pick,b-pick)*multi;
    }
    if(idx%3==0){
        int pick=idx/3;
        ll multi=fact[idx]/fact[pick]/fact[pick]/fact[pick];
        ret+=solve(idx+1,r-pick,g-pick,b-pick)*multi;
    }
    ret+=solve(idx+1,r-idx,g,b);
    ret+=solve(idx+1,r,g-idx,b);
    ret+=solve(idx+1,r,g,b-idx);
    return ret;
}
int main(){
    fact[0]=1;
    for(int i=1;i<11;i++)
        fact[i]=i*fact[i-1];
    memset(cache,-1,sizeof(cache));
    scanf("%d%d%d%d",&N,&R,&G,&B);
    printf("%lld\n",solve(1,R,G,B));
    return 0;
}