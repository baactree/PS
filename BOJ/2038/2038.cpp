#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int main(){
	int n;
	scanf("%d",&n);
	if(n<=2)
		return !printf("%d\n",n);
	dp[1]=1;
	dp[2]=2;
	long long sum=1;
	int ans=1;
	for(int i=2;;i++){
		int cnt=dp[i];
		while(cnt--){
			dp[++ans]=i;
			sum+=i;
			if(sum>=n)
				return !printf("%d\n",ans);
		}
	}
	return 0;
}