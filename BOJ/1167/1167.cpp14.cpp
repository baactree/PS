#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <deque>
#include <utility>
using namespace std;
int N;
vector<pair< int,int > > Map[100001];
int Max;
int sum;
int Max_v;
bool trip[100001];
int distance[100001];
void search(int v,int sum)
{
	if(Max<sum)
	{
		Max=sum;
		Max_v=v;
	}
	trip[v]=true;
	int size=Map[v].size();
	for(int i=0;i<size;i++)
	{
		if(!trip[Map[v][i].first])
		{
			search(Map[v][i].first,sum+Map[v][i].second);
		}
	}
}
int main()
{

//	freopen("sample.txt","r",stdin);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int now;
		int vertex,dist;
		scanf("%d",&now);
		while(true)
		{
			scanf("%d",&vertex);
			if(vertex==-1)
				break;
			scanf("%d",&dist);
			Map[now].push_back(make_pair(vertex,dist));
		}
	}
	Max=0;
	sum=0;
	Max_v=0;
	search(1,0);
	
	Max=0;
	sum=0;
	memset(trip,0,sizeof(trip));
	search(Max_v,0);
	printf("%d\n",Max);
	
	
	
	

//	while(true);

    return 0;
}

	
