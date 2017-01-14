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
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
typedef unsigned long long LLU;
int N, M;
int _pow[101];
int main() {
	cin >> M >> N;
	for (int i = 0; i < 101; i++)
		_pow[i] = i*i;
	int sum = 0;
	int idx = 0;
	int _min = 987654321;
	for (int i = 0; i < 101; i++) {
		if (_pow[i] > N)
			break;
		if (_pow[i] >= M) {
			_min = min(_min,_pow[i]);
			sum += _pow[i];
		}
	}
	if (_min == 987654321)
		printf("-1\n");
	else		
		printf("%d\n%d\n", sum, _min);
	return 0;
}