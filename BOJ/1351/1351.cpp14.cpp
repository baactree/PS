#include "bits/stdc++.h"
using namespace std;
int P,Q;
long long N;
map<long long,long long> cache;
long long solve(long long n){
    if(n==0)
        return 1;
    if(cache.count(n)!=0)
        return cache[n];
    return cache[n]=solve(n/P)+solve(n/Q);
}
int main(){
    scanf("%lld%d%d",&N,&P,&Q);
    printf("%lld\n",solve(N));
    return 0;
}