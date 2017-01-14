#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


using namespace std;
//65 97
int dp[500][500];
int Map[500][500];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			cin>>Map[i][j];
			
	dp[0][0]=Map[0][0];
	for(int i=1;i<N;i++)
	{
		dp[i][0]=Map[i][0]+dp[i-1][0];
		dp[i][i]=Map[i][i]+dp[i-1][i-1];
	}
	
	for(int i=1;i<N;i++)
		for(int j=1;j<i;j++)
		{
			dp[i][j]=max(Map[i][j]+dp[i-1][j-1],Map[i][j]+dp[i-1][j]);
		}
		
		
	int MAx=0;
	for(int i=0;i<N;i++)
		MAx=max(MAx,dp[N-1][i]);
	printf("%d\n",MAx);
	return 0;
}
