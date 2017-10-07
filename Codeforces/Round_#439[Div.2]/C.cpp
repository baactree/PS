#include <bits/stdc++.h>
using namespace std;
int a,b,c;
const int mod=998244353;
typedef long long ll;
ll f[5005];
ll comb[5005][5005];
int main(){
	f[0]=1;
	for(int i=1;i<5005;i++)
		f[i]=(f[i-1]*i)%mod;
	for(int i=0;i<5005;i++){
		comb[i][0]=1;
		for(int j=1;j<=i;j++)
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	scanf("%d%d%d",&a,&b,&c);
	ll ret=1;
	ll sum=0;
	for(int i=0;i<=min(a,b);i++){
		sum+=((comb[a][i]*comb[b][i])%mod*f[i])%mod;
		sum%=mod;
	}
	ret=(ret*sum)%mod;
	sum=0;
	for(int i=0;i<=min(b,c);i++){
		sum+=((comb[b][i]*comb[c][i])%mod*f[i])%mod;
		sum%=mod;
	}
	ret=(ret*sum)%mod;
	sum=0;
	for(int i=0;i<=min(a,c);i++){
		sum+=((comb[a][i]*comb[c][i])%mod*f[i])%mod;
		sum%=mod;
	}
	ret=(ret*sum)%mod;
	printf("%lld\n",ret);
	return 0;
}