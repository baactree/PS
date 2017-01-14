#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int output[9];
int main()
{
	int N;
	cin>>N;
	int temp=0;
	int temp2=N;
	if(N!=1)
	{
	while(true)
	{
		for(int i=0;i<temp;i++)
			printf(" ");
		for(int i=0;i<temp2*2-1;i++)
			printf("*");
		printf("\n");
		temp++;
		temp2--;
		if(temp2==0)
		break;
	}
	temp2=2;
	temp=N-2;
	while(true)
	{
		for(int i=0;i<temp;i++)
			printf(" ");
		for(int i=0;i<temp2*2-1;i++)
			printf("*");
		printf("\n");
		if(temp==0)
			break;
		temp2++;
		temp--;
		
			
	}
}
else
	printf("*\n");
	return 0;
}
