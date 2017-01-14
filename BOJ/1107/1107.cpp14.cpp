#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M;
bool broken[10];
bool possi(int i)
{
	bool flag = true;
	while (true)
	{
		if (broken[i % 10])
			flag = false;
		i /= 10;
		if (i == 0)
			break;
	}
	return flag;
}
int len(int i)
{
	int ret = 0;
	while (true)
	{
		ret++;
		i /= 10;
		if (i == 0)
			break;
	}
	return ret;
}
int main()
{
	cin >> N >> M;
	int bk;

	for (int i = 0; i<M; i++)
	{
		scanf("%d", &bk);
		broken[bk] = true;//부서짐
	}
	int ans = abs(N - 100);
	for (int i = 0; i < 1000000; i++)
	{
		if (possi(i))
		{
			int temp = abs(i - N) + len(i);
			ans = min(ans, temp);
		
		}
	}

	
	printf("%d\n", ans);
	return 0;
}
