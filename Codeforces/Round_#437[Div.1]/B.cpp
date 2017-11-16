#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	int s,a,b;
	bool operator <(const Node &rhs)const{
		return b-a>rhs.b-rhs.a;
	}
};
int n,s;
Node arr[100005];
ll possi(ll x){
	ll ret=0;
	for(int i=0;i<n;i++)
		ret+=(ll)arr[i].s*arr[i].a;
	ll r=x*s;
	for(int i=0;i<n;i++){
		ll temp=min(r,(ll)arr[i].s);
		ret+=(arr[i].b-arr[i].a)*temp;
		r-=temp;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&s);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&arr[i].s,&arr[i].a,&arr[i].b);
		sum+=arr[i].s;
	}
	ll m=(sum+s-1)/s;
	int r=m*s-sum;
	arr[n++]=Node({r,0,0});
	sort(arr,arr+n);
	ll le,ri,ans;
	le=0;
	ri=m;
	ans=0;
	while(le<=ri){
		ll l=(le*2+ri)/3;
		ll r=(le+ri*2)/3;
		ll ls=possi(l);
		ll rs=possi(r);
		if(ls<=rs){
			ans=max(ans,ls);
			le=l+1;
		}
		else{
			ans=max(ans,rs);
			ri=r-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}