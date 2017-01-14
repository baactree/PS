#include <iostream>
#include <stdio.h>

#define X 10007
using namespace std;
int dp[1001];
int Max;
int main()
{
//	freopen("sample.txt","r",stdin);
	
	int N;
	cin>>N;
	int v;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&v);
		for(int j=i;j<=N;j++)
			dp[j]=max(dp[j],dp[j-i]+v);
	}
	
	printf("%d\n",dp[N]);
// 	while(true);
    return 0;
}
