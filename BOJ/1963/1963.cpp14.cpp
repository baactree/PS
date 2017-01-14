#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int A, B;
bool trip[10000];
int cnt[10000];
int store[10000];
bool _prime(int n)
{
	if (n == 0)
		false;
	if (n == 1)
		false;
	if (n == 2)
		true;
	if ((n % 2) == 0)
		false;
	int _sqrt = sqrt(n);
	for (int i = 2; i*i<= n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
void search(int v)
{
	if (store[v] == -1)
		return;
	search(store[v]);
	printf("%d\n", store[v]);
}
int main()
{
	int Case;
	cin >> Case;
	while (Case--)
	{
		memset(trip, 0, sizeof(trip));
		memset(cnt, 0, sizeof(cnt));
		memset(store, -1, sizeof(store));
		cin >> A >> B;
		queue<int> q;
		q.push(A);
		trip[A] = true;
		int now;
		while (!q.empty())
		{
			now = q.front();
			q.pop();
			if (now == B)
				break;
			int temp;
			//첫자리
			for (int i = 1; i < 10; i++)
			{
				temp = now%1000+i*1000;
				if (_prime(temp) && !trip[temp])
				{
					trip[temp] = true;
					cnt[temp] = cnt[now] + 1;
					store[temp] = now;
					q.push(temp);
				}
			}

			//둘자리
			for (int i = 0; i < 10; i++)
			{
				temp = now - (now % 1000 - now % 100) +(i * 100);
				if (_prime(temp) && !trip[temp])
				{
					trip[temp] = true;
					cnt[temp] = cnt[now] + 1;
					store[temp] = now;
					q.push(temp);
				}
			}

			//셋자리
			for (int i = 0; i < 10; i++)
			{
				temp = now - (now % 100 - now % 10) +i * 10;
				if (_prime(temp) && !trip[temp])
				{
					trip[temp] = true;
					cnt[temp] = cnt[now] + 1;
					store[temp] = now;
					q.push(temp);
				}
			}

			//넷자리
			for (int i = 0; i < 10; i++)
			{
				temp = now - (now % 10) +i;
				if (_prime(temp) && !trip[temp])
				{
					trip[temp] = true;
					cnt[temp] = cnt[now] + 1;
					store[temp] = now;
					q.push(temp);
				}
			}

		}
		if (now == B)
		{
			printf("%d\n", cnt[B]);
		//	search(B);
		//	printf("\n");
		}
		else
			printf("Impossible\n");



	}
	
	return 0;
}
