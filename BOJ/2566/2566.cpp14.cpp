#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int Max,mi,mj;
	int input;
	Max=-3;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&input);
			if(Max<input)
			{
				Max=input;
				mi=i;
				mj=j;
			}
		}
	printf("%d\n%d %d\n",Max,mi,mj);
    return 0;
}
