#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10000];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	if (next_permutation(arr, arr + N))
	{
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
