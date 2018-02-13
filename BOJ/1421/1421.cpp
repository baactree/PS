#include <bits/stdc++.h>
using namespace std;
int n,c,w;
int arr[1005];
typedef long long ll;
int main(){
	scanf("%d%d%d",&n,&c,&w);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	ll ans=0;
	for(int i=1;i<=10000;i++){
		ll now=0;
		for(int j=0;j<n;j++){
			ll cnt=arr[j]/i;
			ll cut=(arr[j]+i-1)/i-1;
			if(cnt*i*w>cut*c)
				now+=cnt*i*w-cut*c;
		}
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}