#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
	int sum[5][2];
int main()
{

	int a,b,c,d;
	for(int i=0;i<5;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		sum[i][0]=a+b+c+d;
		sum[i][1]=i+1;
	}
	for(int i=0;i<5;i++)
		for(int j=i+1;j<5;j++)
		if(sum[i][0]>sum[j][0])
		{
			swap(sum[i][0],sum[j][0]);
			swap(sum[i][1],sum[j][1]);
		}
	printf("%d %d\n",sum[4][1],sum[4][0]);
    return 0;
}
