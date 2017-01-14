#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
char Map[8][9];
int main()
{
	int _min, _max;
	_min = 987654321;
	_max = 0;
	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		_min = min(_min, temp);
		_max = max(_max, temp);
	}
	printf("%d\n", _min*_max);
	return 0;	

}
