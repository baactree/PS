#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <queue>
using namespace std;
int N,M;
char Map[100][101];
int dp[100][100];
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
			dp[x][y]=1;
			for(int j=0;j<4;j++)
			{
				int nx= x+dx[j];
				int ny= y+dy[j];
				if(nx==N-1&&ny==M-1)
					return;
				if(safe(nx,ny)&&Map[nx][ny]=='1'&&dp[nx][ny]==0)
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
	cin>>N>>M;
	int cnt=0;
	Edge temp;
	for(int i=0;i<N;i++)
		scanf("%s",Map[i]);
		
		
	idx=0;
	temp.x=0;
	temp.y=0;
	q.push(temp);
	search();
	printf("%d\n",idx+1);
//	while(true);

    return 0;
}

	
