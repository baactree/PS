#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int N;
	cin >> N;
	if (N % 4 == 0 &&( N % 100 != 0 || N % 400 == 0))
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
