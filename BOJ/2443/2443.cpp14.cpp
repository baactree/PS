#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	
	int N;
	cin >> N;
	int temp = 0;
	while (true)
	{
		for (int i = 0; i < temp; i++)
			printf(" ");
		for (int i = 0; i < N * 2 - 1; i++)
			printf("*");
		printf("\n");
		temp++;
		N--;
		if (N == 0)
			break;
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
