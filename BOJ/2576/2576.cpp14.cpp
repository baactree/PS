#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int sum = 0;
	int input;
	int Min = 987654321;
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &input);
		if (input % 2 != 0)
		{
			sum += input;
			Min = min(Min, input);
		}

	}
	if (sum == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, Min);
	return 0;
}
