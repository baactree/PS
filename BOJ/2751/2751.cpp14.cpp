#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>

using namespace std;
bool arr[2000001];
int main()
{
	int N;
	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		arr[temp+1000000] = true;
	}
	for (int i = 0; i < 2000001; i++)
	{
		if (arr[i])
			printf("%d\n", i - 1000000);
	}
	return 0;
}
