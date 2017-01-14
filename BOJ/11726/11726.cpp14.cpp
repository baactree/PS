#include <iostream>
#include <stdio.h>

#define X 10007
using namespace std;
int dp[1001];
int main()
{
//	freopen("sample.txt","r",stdin);
	
	int N;
	cin>>N;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=N;i++)
		dp[i]=(dp[i-1]+dp[i-2])%X;
	printf("%d\n",dp[N]);
// 	while(true);
    return 0;
}
