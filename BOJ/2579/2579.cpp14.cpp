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
int stair[310];
int cache[310][3];
int N;
int Max;
void search(int index,int upper,int sum)
{

	int& ret=cache[index][upper];
	
	if(ret!=0)
	{
		if(ret>=sum)
			return;
	}
	
	
	ret=sum;

		if(index==N)
	{
		Max=max(Max,sum);
		return;
	}
	
	
	if(index>N)
		return;
	
	if(upper!=2)
		search(index+1,upper+1,sum+stair[index+1]);
		
	search(index+2,1,sum+stair[index+2]);
		
}
int main()
{
//	freopen("sample.txt","r",stdin);

	cin>>N;
	for(int i=1;i<=N;i++)
		scanf("%d",&stair[i]);
	Max=0;
	search(0,0,0);
	printf("%d\n",Max);
//	while(true);
    return 0;
}
