
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int sum;
	scanf("%d", &sum);
	int input;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &input);
		sum -= input;
	}
	printf("%d\n", sum);
	return 0; 
}