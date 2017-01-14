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

int main()
{
	priority_queue<int> pq;
	int N;
	cin >> N;
	int in;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &in);
		if (in == 0)
		{
			if (!pq.empty())
			{
				printf("%d\n", pq.top()*(-1));
				pq.pop();
			}
			else
				printf("0\n");
		}
		else
			pq.push(in*(-1));
	}

	return 0;
}
