#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include <deque>
using namespace std;

vector<int> Map[1001];
int N,M;
bool trip[1001];
void search(int v)
{
	trip[v]=true;
	int size=Map[v].size();
	for(int i=0;i<size;i++)
		if(!trip[Map[v][i]])
		{
			search(Map[v][i]);
		}
		
}
int main()
{
	scanf("%d%d",&N,&M);
	int a,b;
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",&a,&b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	int cnt=0;
	for(int i=1;i<=N;i++)
		if(!trip[i])
		{
			search(i);
			cnt++;
		}
		
		
	printf("%d\n",cnt);
	
    return 0;
}
