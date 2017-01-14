#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int temp = 1;
	int temp2 = N - 1;
	if (N != 1)
	{
		while (true)
		{
			for (int i = 0; i < temp; i++)
				printf("*");
			for (int i = 0; i < temp2 * 2; i++)
				printf(" ");
			for (int i = 0; i < temp; i++)
				printf("*");
			printf("\n");
			if (temp2 == 0)
				break;
			temp++;
			temp2--;
		}
		temp = N - 1;
		temp2 = 1;
		while (true)
		{
			for (int i = 0; i < temp; i++)
				printf("*");
			for (int i = 0; i < temp2 * 2; i++)
				printf(" ");
			for (int i = 0; i < temp; i++)
				printf("*");
			printf("\n");
			temp--;
			temp2++;
			if (temp == 0)
				break;
		}
	}
	else
	{
		printf("**");
	}
	return 0;
}
