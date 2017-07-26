#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
    scanf("%lld%lld",&n,&k);
    n%=k*2;
    if(n<k)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}