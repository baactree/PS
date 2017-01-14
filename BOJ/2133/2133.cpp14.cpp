#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int N;

//쪼개지는 경우의수 
int dp[31];
//안 쪼개 지는 경우의수 
int _dp[31];
int main()
{
//	freopen("sample.txt","r",stdin);
	cin>>N;
	dp[0]=1;
	dp[2]=3;
	_dp[2]=3;
	if(N%2==0)
	{
		for(int i=4;i<=N;i+=2)
		{
			dp[i]=_dp[2]*dp[i-2];
			for(int j=4;j<=i;j+=2)
			{
				dp[i]+=2*dp[i-j];
			}
		}
		
		printf("%d\n",dp[N]);
	}
	else
	{
		printf("0\n");
	}
	

 // while(true);
    return 0;
}
