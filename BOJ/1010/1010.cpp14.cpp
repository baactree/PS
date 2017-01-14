#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int nCr[30][30];


int main()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (i == 0)
				nCr[i][j] = 0;
			if (j == 0)
				nCr[i][j] = 1;
			else if (i!=0)
			{
				nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
			}
		}
	int Case;
	cin >> Case;
	while (Case--)
	{
		int a, b;
		cin >> a>> b;
		cout << nCr[b][a] << endl;
	}
}
