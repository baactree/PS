#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> line;
int main()
{
//	freopen("sample.txt","r",stdin);

	int N;
	cin>>N;
	int _swap;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&_swap);
		line.insert(line.begin()+line.size()-_swap,i);		
	} 
	
	for(int i=0;i<N;i++)
		printf("%d ",line[i]);
	printf("\n");

//	while(true);
    return 0;
}
