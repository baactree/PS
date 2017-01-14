#include <iostream>
#include <stdio.h>

#define X 1000000000
typedef unsigned long long LLU;
using namespace std;
LLU dp[101][10];
LLU ans[101];
int main()
{
//	freopen("sample.txt","r",stdin);
	
	int N;
	cin>>N;
	dp[1][0]=0;
	for(int i=1;i<10;i++)
		dp[1][i]=1;
	for(int i=2;i<=N;i++)
	{
		dp[i][0]=dp[i-1][1];
		dp[i][9]=dp[i-1][8];
		for(int j=1;j<=8;j++)
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%X;
	}
	LLU ans=0;
	for(int i=0;i<10;i++)
		ans=(ans+dp[N][i])%X;
	printf("%llu\n",ans);
 //	while(true);
    return 0;
}
