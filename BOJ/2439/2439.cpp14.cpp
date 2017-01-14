#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	N--;
	int temp=1;
	while(N>=0)
	{
		for(int i=0;i<N;i++)
			printf(" ");
		for(int i=0;i<temp;i++)
			printf("*");
		printf("\n");
		N--;
		temp++;
	}
    return 0;
}
