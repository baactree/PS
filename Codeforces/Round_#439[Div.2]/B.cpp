#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	if(a==b)
		return !printf("1\n");
	int len=b-a;
	if(b-a>=10)
		return !printf("0\n");
	int ret=1;
	for(int i=0;i<len;i++){
		ret=ret*((a+1+i)%10);
		ret%=10;
	}
	printf("%d\n",ret);
	return 0;
}