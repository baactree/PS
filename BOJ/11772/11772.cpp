#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10];
int n;
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
		ll t=arr[i]%10;
		arr[i]/=10;
		sum+=pow(arr[i],t);
	}
	printf("%lld\n",sum);
	return 0;
}