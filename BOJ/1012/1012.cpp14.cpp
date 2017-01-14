#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int Map[50][50];
int dp[50][50];
int N,M,K;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x, int y)
{
	return (x>=0&&x<N&&y>=0&&y<M);
}
void search(int x,int y)
{
	dp[x][y]=1;
	for(int i=0;i<4;i++)
	{
		if(safe(x+dx[i],y+dy[i])&&Map[x+dx[i]][y+dy[i]]==1&&dp[x+dx[i]][y+dy[i]]==-1)
		{
			search(x+dx[i],y+dy[i]);
		}
	}
}

int main()
{
	
//	freopen("sample.txt", "r", stdin);
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		memset(dp,-1,sizeof(dp));
		memset(Map,0,sizeof(Map));
		int x,y;
		scanf("%d%d%d",&M,&N,&K);
		for(int i=0;i<K;i++)
		{
			scanf("%d%d",&y,&x);
			Map[x][y]=1;
		}
		int cnt=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				if(Map[i][j]==1&&dp[i][j]==-1)
				{
					search(i,j);
					cnt++;
				}
			}
		
		printf("%d\n",cnt);
	}
	return 0;
}
