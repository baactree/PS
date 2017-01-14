#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=N-i-1;j<N;j++)
			printf("*");
			printf("\n");		}
    return 0;
}
