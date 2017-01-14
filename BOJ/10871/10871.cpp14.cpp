#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int input;
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &input);
		if (input < b)
			printf("%d ", input);
	}

	return 0;
}
