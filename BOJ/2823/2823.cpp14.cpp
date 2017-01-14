#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
using namespace std;
string in;
int R, C;
char Map[10][11];
char _Map[12][12];
int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		scanf("%s", Map[i]);
	for (int i = 0; i < R + 2; i++)
		for (int j = 0; j < C + 2; j++)
			_Map[i][j] = 'X';
	for (int i = 1; i < R + 1; i++)
		for (int j = 1; j < C + 1; j++)
			_Map[i][j] = Map[i - 1][j - 1];

	bool flag = true;
	for (int i = 1; i < R + 1; i++)
		for (int j = 1; j < C + 1;j++)
			if (_Map[i][j] == '.') {
				if (_Map[i + 1][j] == 'X'&&
					_Map[i][j - 1] == 'X'&&_Map[i][j + 1] == 'X')
					flag = false;
				else if (_Map[i - 1][j] == 'X'&&
					_Map[i][j - 1] == 'X'&&_Map[i][j + 1] == 'X')
					flag = false;
				else if (_Map[i - 1][j] == 'X'&&_Map[i + 1][j] == 'X'&&
					_Map[i][j + 1] == 'X')
					flag = false;
				else if (_Map[i - 1][j] == 'X'&&_Map[i + 1][j] == 'X'&&
					_Map[i][j - 1] == 'X')
					flag = false;
			}
	if (flag)
		printf("0\n");
	else
		printf("1\n");

	return  0;
}