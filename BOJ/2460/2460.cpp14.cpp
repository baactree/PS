#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int sum=0;
	int MAX=0;
	int in,out;
	for(int i=0;i<10;i++)
	{
		scanf("%d%d",&in,&out);
		sum-=in;
		if(sum<0)
			sum=0;
		sum+=out;
		if(sum>=10000)
			sum=10000;
		MAX=max(MAX,sum);
	}
	printf("%d\n",MAX);
	return 0;
}
