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

vector<int> Map[101];
bool trip[101];
int V,E;
int cnt;
void search(int v)
{
	trip[v]=true;
	cnt++;
	int size=Map[v].size();
	for(int i=0;i<size;i++)
		if(!trip[Map[v][i]])
			search(Map[v][i]);
}
int main()
{
	cin>>V>>E;
	int a,b;
	for(int i=0;i<E;i++)
	{
		scanf("%d%d",&a,&b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	cnt=0;
	search(1);
	printf("%d\n",cnt-1);
    return 0;
}
