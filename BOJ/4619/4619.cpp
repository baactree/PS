#include <bits/stdc++.h>
using namespace std;
int b,n;
typedef long long ll;
ll p(ll x){
	ll ret=1;
	for(int i=0;i<n;i++){
		ret*=x;
		if(ret>1e12)
			return -1;
	}
	return ret;
}
bool possi(int x){
	ll temp=p(x);
	if(temp==-1)
		return false;
	return temp<=b;
}
int main(){
	while(true){
		scanf("%d%d",&b,&n);
		if(b==0&&n==0)
			break;
		int le,ri,mid,ans;
		le=1;
		ri=b;
		ans=0;
		while(le<=ri){
			mid=(le+ri)/2;
			if(possi(mid)){
				ans=mid;
				le=mid+1;
			}
			else
				ri=mid-1;
		}
		ll diff=abs(p(ans)-b);
		ll temp=p(ans+1);
		if(temp!=-1)
			if(abs(temp-b)<diff)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}