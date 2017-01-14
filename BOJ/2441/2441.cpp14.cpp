#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int temp=0;
	while(N)
	{
		for(int i=0;i<temp;i++)
			printf(" ");
		for(int i=0;i<N;i++)
			printf("*");
		printf("\n");
		N--;
		temp++;
	}
    return 0;
}
