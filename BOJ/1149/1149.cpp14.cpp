
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int cache[1000][3];//RGB 0 1 2
int input[1000][3];
int search(int index, int rgb)
{
	int& ret = cache[index][rgb];
	if (ret != 0)
		return ret;
	if (index < 0)
		return 0;
	ret = 987654321;
	for (int i = 0; i < 3; i++)
		if (i != rgb)
		{
			ret = min(ret, search(index - 1, i) + input[index][i]);
		}
	return ret;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d%d%d", &input[i][0], &input[i][1], &input[i][2]);

	printf("%d\n", search(N, 3));
	return 0; 
}