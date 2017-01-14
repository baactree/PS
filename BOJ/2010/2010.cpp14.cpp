#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int nCr[30][30];


int main()
{
	int N;
	cin >> N;
	int output = 1;
	output -= N;
	int input;
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&input);
		output += input;
	}
	printf("%d\n", output);
}
