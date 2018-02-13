#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
ll possi(ll x){
	ll cnt=0;
	while(x){
		cnt+=x/5;
		x/=5;
	}
	return cnt;
}
int main(){
	scanf("%d",&m);
	ll le,ri,mid,ans;
	ans=-1;
	le=0;
	ri=1e15;
	while(le<=ri){
		mid=(le+ri)/2;
		ll cnt=possi(mid);
		if(cnt<m)
			le=mid+1;
		else if(cnt>m)
			ri=mid-1;
		else{
			ans=mid;
			ri=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}