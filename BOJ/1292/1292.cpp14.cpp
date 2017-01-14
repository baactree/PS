
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int sum[1001];
int main()
{
	int index = 0;
	int i = 1;
	while (true)
	{
		for (int j = 0; j < i; j++)
		{
			sum[index++] = i;
			if (index == 1001)
				break;
		}
		i++;
		if (index == 1001)
			break;
	}
	int a, b;
	cin >> a >> b;
	a--; b--;
	int SUM = 0;
	for (int i = a; i <= b; i++)
		SUM += sum[i];
	printf("%d\n", SUM);
	return 0; 
}