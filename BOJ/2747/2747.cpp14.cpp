
#include <iostream>
#include <stdio.h>

using namespace std;
int fibo[46];
int main()
{
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i < 46; i++)
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	int N;
	cin >> N;
	printf("%d\n", fibo[N]);
	return 0; 
}