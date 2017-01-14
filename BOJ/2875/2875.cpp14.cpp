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
#include <deque>

using namespace std;
int N, M, K;

int main()
{
	cin >> N >> M >> K;
	while (K !=0)
	{
		if (N == 0)
		{
			M--;
			K--;
		}
		else if (M == 0)
		{
			N--;
			K--;
		}
		else if(N <=M*2)
		{
			M--;
			K--;
		}
		else if (N > M * 2)
		{
			N--;
			K--;
		}
	}
	printf("%d\n", min(M,N/2));
	return 0;
}
