#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int N;

unsigned long long int dp[101];
int main()
{
//	freopen("sample.txt","r",stdin);
	int Case;
	cin>>Case;
	while(Case--)
	{
		cin>>N;
		dp[1]=1;
		dp[2]=1;
		dp[3]=1;
		dp[4]=2;
		dp[5]=2;
		for(int i=6;i<=N;i++)
			dp[i]=dp[i-1]+dp[i-5];
		printf("%llu\n",dp[N]);
	}
 // while(true);
    return 0;
}
