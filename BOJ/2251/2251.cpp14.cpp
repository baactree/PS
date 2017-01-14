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
vector<int> store;
int A, B, C;
bool cache[201][201][201];
void search(int a, int b, int c)
{
	if (cache[a][b][c] != 0)
		return;
	cache[a][b][c] = 1;
	if (a == 0)
		store.push_back(c);
	if (a != 0)
	{
		if ((B - b) <= a)
			search(a - (B - b), B, c);
		else
			search(0, b + a, c);
		if ((C - c) <= a)
			search(a - (C - c), b, C);
		else
			search(0, b, c + a);
	}
	if (b != 0)
	{
		if ((A - a) <= b)
			search(A, b - (A - a), c);
		else
			search(a + b, 0, c);
		if ((C - c) <= b)
			search(a, b - (C - c), C);
		else
			search(a, 0, b + c);
	}
	if (c != 0)
	{
		if ((A - a) <= c)
			search(A, b, c - (A - a));
		else
			search(a + c, b, 0);
		if ((B - b) <= c)
			search(a, B, c - ((B - b)));
		else
			search(a, b + c, 0);
	}

}
int main()
{
	cin >> A >> B >> C;
	search(0, 0, C);
	sort(store.begin(), store.end());
	int len = store.size();
	for (int i = 0; i < len; i++)
		printf("%d ", store[i]);
	printf("\n");
	return 0;
}
