#include <bits/stdc++.h>
using namespace std;
int q,x,y;
typedef long long ll;
ll f[2000005];
ll fi[2000005];
const ll mod=1e9+7;
ll p(ll a,ll b){
	ll r=a;
	ll ret=1;
	while(b){
		if(b&1)
			ret=(ret*r)%mod;
		b>>=1;
		r=(r*r)%mod;
	}
	return ret;
}
bool prime[1005];
vector<int> pivot;
ll nhr(ll n,ll r){
	ll a=n+r-1;
	ll b=r;
	ll ret=(f[a]*fi[b])%mod;
	ret=(ret*fi[a-b])%mod;
	return ret;
}
int main(){
	for(int i=2;i<1005;i++){
		if(!prime[i]){
			pivot.push_back(i);
			for(int j=i+i;j<1005;j+=i)
				prime[j]=true;
		}
	}
	f[0]=1;
	for(int i=1;i<2000005;i++)
		f[i]=(f[i-1]*i)%mod;
	fi[2000004]=p(f[2000004],mod-2);
	for(int i=2000004;i>0;i--)
		fi[i-1]=(fi[i]*i)%mod;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		vector<int> pp;
		for(int i=0;i<pivot.size();i++){
			if(x==1)
				break;
			int now=pivot[i];
			int cnt=0;
			while(x%now==0){
				cnt++;
				x/=now;
			}
			if(cnt)
				pp.push_back(cnt);
		}
		if(x!=1)
			pp.push_back(1);
		ll ans=1;
		for(int i=0;i<pp.size();i++){
			ans=(ans*nhr(y,pp[i]))%mod;
		}
		ans=(ans*p(2,y-1))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}