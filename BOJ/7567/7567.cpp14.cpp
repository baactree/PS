
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
int main()
{
	int sum = 0;
	char input[51];
	char begin;
	scanf("%s", input);
	for (int i = 0; i < strlen(input); i++)
	{
		if (i == 0)
		{
			sum += 10;
			begin = input[i];
		}
		else
		{
			if (input[i] == begin)
			{
				sum += 5;
				begin = input[i];
			}
			else
			{
				sum += 10;
				begin = input[i];
			}
		}
	}
	printf("%d\n", sum);
	return 0; 
}