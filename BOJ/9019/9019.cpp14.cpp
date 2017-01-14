#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
char Map[10001];
int road[10001];
bool trip[10001];
int A, B;

void output(int v)
{
	if (Map[v]==0)
		return;
	output(road[v]);
	printf("%c", Map[v]);
	return;
}
int main()
{
	int Case;
	cin >> Case;
	while (Case--)
	{
		memset(trip, 0, sizeof(trip));
		memset(Map, 0, sizeof(Map));
		memset(road, -1, sizeof(road));
		cin >> A >> B;
		queue<int> q;
		q.push(A);
		trip[A] = true;
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			if (now == B)
				break;
			int temp;
			temp = (now*2)%10000;

			if (!trip[temp])
			{
				trip[temp] = true;
				Map[temp] = 'D';
				road[temp] = now;
				q.push(temp);
			}
			temp = now - 1;
			if (temp < 0)
				temp = 9999;
			if ( !trip[temp])
			{
				trip[temp] = true;
				Map[temp] = 'S';
				road[temp] = now;
				q.push(temp);
			}
			temp = now;
			temp = (temp % 1000) * 10 + temp / 1000;
			if ( !trip[temp])
			{
				trip[temp] = true;
				Map[temp] = 'L';
				road[temp] = now;
				q.push(temp);
			}

			temp = now;
			temp = (temp % 10) * 1000 + temp / 10;

			if ( !trip[temp])
			{
				trip[temp] = true;
				Map[temp] = 'R';
				road[temp] = now;
				q.push(temp);
			}
		}

		output(B);
		printf("\n");
	}
	return 0;
}
