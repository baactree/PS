#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char input[50][51];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", input[i]);
	char output[51];
	int _strlen = strlen(input[0]);
	for (int i = 0; i <= _strlen; i++)
		output[i] = input[0][i];
	for (int i = 0; i < _strlen; i++)
		for (int j = 1; j < N; j++)
		{

			if (input[0][i] != input[j][i])
			{
				output[i] = '?';
				break;
			}
			output[i] = input[0][i];

		}
	output[_strlen] = 0;
	printf("%s\n", output);
	return 0;
}
