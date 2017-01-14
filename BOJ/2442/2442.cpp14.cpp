#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int temp = N - 1;
	int temp2 = N - temp;
	while (true)
	{
		for (int i = 0; i < temp; i++)
			printf(" ");
		for (int i = 0; i < temp2*2-1; i++)
			printf("*");
		printf("\n");
		if (temp == 0)
			break;
		temp--;
		temp2++;
		
	}
	return 0;	

}
