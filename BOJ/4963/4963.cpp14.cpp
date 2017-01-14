#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
using namespace std;
int dp[50][50];
int N,M;
int Map[50][50];
int idx;
int dx[8]={-1,1,0,0,-1,1,-1,1};
int dy[8]={0,0,-1,1,1,1,-1,-1};
bool safe(int x, int y)
{
	return x>=0&&y>=0&&x<N&&y<M;
}
void search(int x, int y)
{
	dp[x][y]=idx;
	for(int i=0;i<8;i++)
	{
		if(safe(x+dx[i],y+dy[i])&&Map[x+dx[i]][y+dy[i]]==1&&
		dp[x+dx[i]][y+dy[i]]==0)
			search(x+dx[i],y+dy[i]);
	}
}
int main()
{

//	freopen("sample.txt","r",stdin);
	while(true)
	{
		cin>>M>>N;
		if(M==0&&N==0)
			break;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				scanf("%d",&Map[i][j]);
		idx=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(dp[i][j]==0&&Map[i][j]==1)
				{
					idx++;
					search(i,j);
				}
				
				
		printf("%d\n",idx);
	}
//	while(true);

    return 0;
}

	
