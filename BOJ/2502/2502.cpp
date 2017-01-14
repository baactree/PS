#include <iostream>

using namespace std;
int dp[31];

int main(void)
{
	int D,K;
	cin>>D>>K;
//a/b/ab/abb/aabbb/
//	a*dp[i-2]+b*dp[i-1]
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<31;i++)
		dp[i]=dp[i-1]+dp[i-2];
	for(int i=1;i<K/dp[D-1];i++)
	{
		if((K-i*dp[D-2])%dp[D-1]==0)
		{
			cout<<i<<endl<<(K-i*dp[D-2])/dp[D-1]<<endl;
		
			return 0;
		}
	}
	return 0;
	
}