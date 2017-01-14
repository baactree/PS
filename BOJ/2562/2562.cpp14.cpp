#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int input[9];
	int MAX = 0;
	int index;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &input[i]);
		if (MAX < input[i])
		{
			MAX = input[i];
			index = i + 1;
		}

	}
	printf("%d\n%d\n", MAX, index);
	return 0;
}
