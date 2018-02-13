#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
const int mod=1e9+7;
ll _pow(ll a,ll b){
	if(b==0)
		return 1;
	ll temp=_pow(a,b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		return (temp*a)%mod;
	return temp;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==-1&&(n+m)&1)
		return !printf("0\n");
	n=(n-1);
	m=(m-1);
	ll ans=_pow(2,n);
	ans=_pow(ans,m);
	printf("%lld\n",ans);
	return 0;
}