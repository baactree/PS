#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cnt[10];
bool chk(ll x){
	while(x){
		cnt[x%10]=1;
		x/=10;
	}
	for(int i=0;i<10;i++)
		if(!cnt[i])
			return false;
	return true;
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		ll n;
		scanf("%lld",&n);
		if(n==0){
			printf("Case #%d: INSOMNIA\n",tc);
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		int k=1;
		while(!chk(n*k))
			k++;
		printf("Case #%d: %ld\n",tc,n*k);
	}
	return 0;
}