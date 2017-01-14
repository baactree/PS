
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int Case;
	cin >> Case;
	while (Case--)
	{
		int sum = 0;
		int input;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &input);
			sum += input;
		}
		printf("%d\n", sum);
	
	}
	return 0; 
}