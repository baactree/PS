#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <queue>
using namespace std;
int N,M;
int Map[1000][1000];
int dp[1000][1000];
int idx;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Edge{
	int x,y;
};
queue<Edge> q;
bool safe(int x, int y)
{
	return x>=0&&y>=0&&x<N&&y<M;
}
void search()
{
	Edge st;
	int x,y;
	Edge temp;
	while(!q.empty())
	{
		
		
		
		idx++;
		int size=q.size();
		for(int i=0;i<size;i++)
		{
			st=q.front();
			q.pop();
			x=st.x;
			y=st.y;
			Map[x][y]=1;
			dp[x][y]=1;
			for(int j=0;j<4;j++)
			{
				int nx= x+dx[j];
				int ny= y+dy[j];
				if(safe(nx,ny)&&Map[nx][ny]==0&&dp[nx][ny]==0)
				{
					dp[nx][ny]=1;
					temp.x=nx;
					temp.y=ny;
					q.push(temp);
				}
		
			}
		}
		
		
		
	}
}
int main()
{

//	freopen("sample.txt","r",stdin);
	cin>>M>>N;
	int cnt=0;
	Edge temp;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			scanf("%d",&Map[i][j]);
			if(Map[i][j]==1)
			{
				temp.x=i;
				temp.y=j;
				q.push(temp);
			}
			else if(Map[i][j]==0)
				cnt++;
		}
	idx=0;
	if(cnt!=0)
	{
		idx--;
		search();
		cnt=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				if(Map[i][j]==0)
					cnt++;
				
			}
		if(cnt!=0)
			idx=-1;
	}
	
			
	printf("%d\n",idx);
//	while(true);

    return 0;
}

	
