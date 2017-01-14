#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef map<string, int> StateMap;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y)
{
	return (x >= 0 && y >= 0&&x < 3 && y < 3);
}
int search(string start, string finish)
{
	if (start == finish)
		return 0;
	StateMap c;

	queue<string> q;
	q.push(start);
	c[start] = 0;
	while (!q.empty())
	{
		string here = q.front();
		q.pop();
		int cost = c[here];
		//
		int idx = here.find('0');
		//행
		int x = idx / 3;
		//열
		int y = idx % 3;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
				
			if (safe(nx, ny))
			{
				int _idx = nx * 3 + ny;
				swap(here[idx], here[_idx]);
				if (c.count(here) == 0)
				{
					if (here == finish)
						return cost + 1;
					c[here] = cost + 1;
					q.push(here);
				}
				swap(here[idx], here[_idx]);

			}
		}

	}
	return -1;
}
int main()
{
	string start = "";
	string finish = "123456780";
	int temp;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &temp);
		start += (char)(temp+48);
	}
	printf("%d\n", search(start, finish));
	
	return 0;
}
