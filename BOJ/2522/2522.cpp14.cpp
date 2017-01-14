
#include <iostream>
#include <stdio.h>
#include <algorithm>

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
			for (int i = 0; i < temp2; i++)
				printf(" ");
			for (int i = 0; i < temp; i++)
				printf("*");
			printf("\n");

			if (temp2 == 0)
				break;
			temp2--;
			temp++;
		}
		temp = N - 1;
		temp2 = 1;
		while (true)
		{
			for (int i = 0; i < temp2; i++)
				printf(" ");
			for (int i = 0; i < temp; i++)
				printf("*");
			printf("\n");
			temp2++;
			temp--;
			if (temp == 0)
				break;
		}
	}
	else
		printf("*\n");
	return 0; 
}