#include <stdio.h>
#include <iostream>
using namespace std;
char Map[8][9];
int main()
{
	int N;
	cin >> N;
	int temp = N - 1;
	int temp2 = 1;
	if (N != 1)
	{
		while (true)
		{
			for (int i = 0; i < temp; i++)
				printf(" ");
			for (int i = 0; i < temp2 * 2 - 1; i++)
				printf("*");
			printf("\n");
			if (temp == 0)
				break;
			temp--;
			temp2++;

		}
		temp2 = 1;
		temp = N - 1;
		while (true)
		{
			for (int i = 0; i < temp2; i++)
				printf(" ");
			for (int i = 0; i < temp * 2 - 1; i++)
				printf("*");
			printf("\n");
			temp--;
			temp2++;
			if (temp == 0)
				break;
		}
	}
	else
		printf("*\n");
	return 0;	

}
