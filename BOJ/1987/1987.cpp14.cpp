#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
bool alpa[26];
string Map[20];
int R, C;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y)
{
	return (x >= 0 && y >= 0 && x < R&&y < C);
}
int search(int x, int y)
{
	if (!safe(x, y))
		return 0;
	if (alpa[Map[x][y] - 65])
		return 0;
	alpa[Map[x][y] - 65] = true;

	int ret = 0;
	for (int i = 0; i < 4; i++)
		ret = max(ret, search(x + dx[i], y + dy[i]) + 1);

	alpa[Map[x][y] - 65] = false;
	return ret;

}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> Map[i];
	printf("%d\n", search(0, 0));
	return 0;
}
