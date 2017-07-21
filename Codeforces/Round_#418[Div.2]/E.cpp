#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n;
int d[50];
int cache[50][25*25][25*25+1];
int solve(int idx,ll n1,ll n2,ll p1,ll p2,ll p3){
    //cout<<idx<<" "<<n1<<" "<<n2<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
    if(idx==n){
        ll s=n1+n2+p1+p2+p3;
        return s==0;
    }
    if(p1+p2+p3==0){
        if(n1+n2==0)
            return 0;
        return solve(idx,0,0,n1,n2,0);
    }
    int &ret=cache[idx][n1+n2*25][p1+p2*25+p3*25*25];
    if(ret!=-1)
        return ret;
    ret=0;
    if(d[idx]==2){
        if(p3>0){
            //n2-1
            if(n2>0)
                ret=(ret+p3*n2*solve(idx+1,n1+1,n2-1,p1,p2+1,p3-1))%mod;
            //n1-1
            if(n1>0)
                ret=(ret+p3*n1*solve(idx+1,n1-1,n2,p1,p2+1,p3-1))%mod;
            ret=(ret+p3*solve(idx+1,n1+1,n2,p1,p2+1,p3-1))%mod;
        }
        if(p2>0){
            //n2-1
            if(n2>0)
                ret=(ret+p2*n2*solve(idx+1,n1+1,n2-1,p1+1,p2-1,p3))%mod;
            //n1-1
            if(n1>0)
                ret=(ret+p2*n1*solve(idx+1,n1-1,n2,p1+1,p2-1,p3))%mod;
            ret=(ret+p2*solve(idx+1,n1+1,n2,p1+1,p2-1,p3))%mod;
        }
        if(p1>0){
            //n2-1
            if(n2>0)
                ret=(ret+p1*n2*solve(idx+1,n1+1,n2-1,p1-1,p2,p3))%mod;
            //n1-1
            if(n1>0)
                ret=(ret+p1*n1*solve(idx+1,n1-1,n2,p1-1,p2,p3))%mod;
            ret=(ret+p1*solve(idx+1,n1+1,n2,p1-1,p2,p3))%mod;
        }
        return ret;
    }
    if(p3>0){
        // n2에서 2개 뽑기
        if(n2>1)
            ret=(ret+(n2*(n2-1)/2)*p3*solve(idx+1,n1+2,n2-2,p1,p2+1,p3-1))%mod;
        // n1 한 개 n2 한 개 뽑기
        if(n2>0&&n1>0)
            ret=(ret+n2*n1*p3*solve(idx+1,n1,n2-1,p1,p2+1,p3-1))%mod;
        // n1 2개 뽑기
        if(n1>1)
            ret=(ret+(n1*(n1-1)/2)*p3*solve(idx+1,n1-2,n2,p1,p2+1,p3-1))%mod;
        // n2-1, n1+1
        if(n2>0)
            ret=(ret+n2*p3*solve(idx+1,n1+2,n2-1,p1,p2+1,p3-1))%mod;
        // n1-1, n1+1
        if(n1>0)
            ret=(ret+n1*p3*solve(idx+1,n1,n2,p1,p2+1,p3-1))%mod;
        // n2+1
        ret=(ret+p3*solve(idx+1,n1,n2+1,p1,p2+1,p3-1))%mod;
    }
    if(p2>0){
        // n2에서 2개 뽑기
        if(n2>1)
            ret=(ret+(n2*(n2-1)/2)*p2*solve(idx+1,n1+2,n2-2,p1+1,p2-1,p3))%mod;
        // n1 한 개 n2 한 개 뽑기
        if(n2>0&&n1>0)
            ret=(ret+n2*n1*p2*solve(idx+1,n1,n2-1,p1+1,p2-1,p3))%mod;
        // n1 2개 뽑기
        if(n1>1)
            ret=(ret+(n1*(n1-1)/2)*p2*solve(idx+1,n1-2,n2,p1+1,p2-1,p3))%mod;
        // n2-1, n1+1
        if(n2>0)
            ret=(ret+n2*p2*solve(idx+1,n1+2,n2-1,p1+1,p2-1,p3))%mod;
        // n1-1, n1+1
        if(n1>0)
            ret=(ret+n1*p2*solve(idx+1,n1,n2,p1+1,p2-1,p3))%mod;
        // n2+1
        ret=(ret+p2*solve(idx+1,n1,n2+1,p1+1,p2-1,p3))%mod;
    }
    if(p1>0){
        // n2에서 2개 뽑기
        if(n2>1)
            ret=(ret+(n2*(n2-1)/2)*p1*solve(idx+1,n1+2,n2-2,p1-1,p2,p3))%mod;
        // n1 한 개 n2 한 개 뽑기
        if(n2>0&&n1>0)
            ret=(ret+n2*n1*p1*solve(idx+1,n1,n2-1,p1-1,p2,p3))%mod;
        // n1 2개 뽑기
        if(n1>1)
            ret=(ret+(n1*(n1-1)/2)*p1*solve(idx+1,n1-2,n2,p1-1,p2,p3))%mod;
        // n2-1, n1+1
        if(n2>0)
            ret=(ret+n2*p1*solve(idx+1,n1+2,n2-1,p1-1,p2,p3))%mod;
        // n1-1, n1+1
        if(n1>0)
            ret=(ret+n1*p1*solve(idx+1,n1,n2,p1-1,p2,p3))%mod;
        // n2+1
        ret=(ret+p1*solve(idx+1,n1,n2+1,p1-1,p2,p3))%mod;
    }
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    if(d[0]==2)
        printf("%d\n",solve(1,0,0,0,1,0));
    else
        printf("%d\n",solve(1,0,0,0,0,1));
    return 0;
}