
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int input[3];
	scanf("%d%d%d", &input[0], &input[1], &input[2]);
	sort(input, input + 3);
	printf("%d\n", input[1]);
	return 0; 
}