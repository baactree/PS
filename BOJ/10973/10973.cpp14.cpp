#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
typedef long long int ll;
int main()
{
	int N;
	cin >> N;
	int arr[10000];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	if (prev_permutation(arr, arr + N))
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
	else
		printf("-1");
	printf("\n");
	return 0;
}