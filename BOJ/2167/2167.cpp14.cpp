#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int input[300][300];
int main()
{
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>input[i][j];
	int K;
	cin>>K;
	while(K--)
	{
		
		int sum=0;
		int sx,sy,fx,fy;
		cin>>sx>>sy>>fx>>fy;
		sx--;
		sy--;
		fx--;
		fy--;
		for(int i=sx;i<=fx;i++)
			for(int j=sy;j<=fy;j++)
				sum+=input[i][j];
		printf("%d\n",sum);
		
	}
	return 0;
}
