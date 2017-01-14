#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
	
	for(int i=N-1;i>=1;i--)
	{
		for(int j=i;j>0;j--)
			printf("*");
		printf("\n");
	}

	
	
    return 0;
}
