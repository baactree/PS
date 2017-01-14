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
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int ans = -1;
	while (true)
	{
		int sum=0;
		for (int i = 0; i < N-1; i++)
			sum += abs(arr[i] - arr[i + 1]);
		ans = max(ans, sum);
		if (!next_permutation(arr, arr + N))
			break;
	}
	printf("%d\n", ans);
	return 0;
}
