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
vector<int> Map[100001];
int parent[100001];
bool trip[100001];

void search(int v)
{
	queue<int> q;
	q.push(v);
	parent[v]=0;
	while(!q.empty())
	{
		int size=q.size();
		for(int i=0;i<size;i++)
		{
			int temp=q.front();
			q.pop();
				int _size=Map[temp].size();
				for(int j=0;j<_size;j++)
				{
					if(!trip[Map[temp][j]])
					{
						parent[Map[temp][j]]=temp;
						trip[Map[temp][j]]=true;
						q.push(Map[temp][j]);
					}
				}
			
		}
	}
}
int main()
{

//	freopen("sample.txt","r",stdin);
	cin>>N;
	int a,b;
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&a,&b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	
	search(1);

	for(int i=2;i<=N;i++)
	{
		printf("%d\n",parent[i]);
	}

//	while(true);

    return 0;
}

	
