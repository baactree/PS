#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g,t,a,d;
int main(){
	while(true){
		scanf("%lld%lld%lld%lld",&g,&t,&a,&d);
		if(g==-1&&t==-1&&a==-1&&d==-1)
			break;
		ll ans=g*(t*(t-1)/2);
		ll cnt=g*a+d;
		ll r=1;
		while(r<cnt)
			r*=2;
		ll y=r-cnt;
		ans+=r-1;
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,ans,y);
	}
	return 0;
}