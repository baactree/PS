#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100005];
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&n);
		int sum=0;
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			sum+=a;
			for(int j=sum;j>=0;--j){
				dp[j]+=b;
				if(j>=a)
					dp[j]=min(dp[j],dp[j-a]);
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=0;i<=sum;i++)
			ans=min(ans,max(i,dp[i]));
		printf("%d\n",ans);
	}
	return 0;
}