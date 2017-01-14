#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N;
int dp[12];
int main()
{
	
//	freopen("sample.txt", "r", stdin);
	int Case;
	scanf("%d",&Case);
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4;i<12;i++)
		dp[i]=dp[i-2]+dp[i-1]+dp[i-3];
	while(Case--)
	{
		scanf("%d",&N);
		printf("%d\n",dp[N]);
	}
	
	return 0;
}
