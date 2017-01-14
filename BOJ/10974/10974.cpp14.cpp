#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int arr[8];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	
	while (true)
	{
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
		printf("\n");
		if (!next_permutation(arr, arr + N))
			break;
	}
	return 0;
}
