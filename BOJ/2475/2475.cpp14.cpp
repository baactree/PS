#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	unsigned long long int input[5];
	for (int i = 0; i < 5; i++)
		scanf("%llu", &input[i]);
	unsigned long long int sum = 0; 
	for (int i = 0; i < 5; i++)
		sum += ((input[i] * input[i]));
	printf("%llu\n", sum%10);
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
