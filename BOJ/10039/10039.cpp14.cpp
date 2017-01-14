#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int sum=0;
	for(int i=0;i<5;i++)
	{
		int in;
		scanf("%d",&in);
		if(in<=40)
			sum+=40;
		else
			sum+=in;
	}
	printf("%d\n",sum/5);
	return 0;
}
