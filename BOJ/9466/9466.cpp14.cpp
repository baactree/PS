#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
using namespace std;
int N;
int Map[100001];
int trip[100001];
bool check[100001];
bool _check[100001];
int cnt;
void _checking(int v)
{
	cnt++;
	check[v]=true;
	if(!check[Map[v]])
		_checking(Map[v]);
}
void search(int v,int m)
{
	trip[v]=m;
	_check[v]=true;
	if(trip[Map[v]]!=m&&!check[Map[v]])
	{
		if(!_check[Map[v]])
			search(Map[v],m);
	}
	else
		if(!check[Map[v]])
			_checking(Map[v]);
}
int main()
{

//	freopen("sample.txt","r",stdin);
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		
		scanf("%d",&N);
		memset(check,0,sizeof(bool)*(N+1));
		memset(trip,0,sizeof(int)*(N+1));
		memset(_check,0,sizeof(bool)*(N+1));
		int mode=1;
		for(int i=1;i<=N;i++)
			scanf("%d",&Map[i]);
		cnt=0;
		for(int i=1;i<=N;i++)
			if(!check[i]&&!_check[i])
			{
				search(i,mode);
				mode++;
			}
		
		printf("%d\n",N-cnt);
		
	}
//	while(true);

    return 0;
}
