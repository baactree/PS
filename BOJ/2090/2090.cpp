#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[10];
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d",&n);
    ll r=1;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        r*=arr[i];
    }
    ll p=0;
    for(int i=0;i<n;i++){
        ll q=r/arr[i];
        p+=q;
    }
    ll g=gcd(r,p);
    printf("%lld/%lld\n",r/g,p/g);
    return 0;
}