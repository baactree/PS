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
#include <cmath>
using namespace std;
char str[2510];
bool possi[2510][2510];
int N;
extern inline void search(int pivot) {
	int left = pivot;
	int right = pivot;
	int k = 0;
	while (left - k >= 0 && right + k < N) {
		if (str[left - k] == str[right + k])
			possi[left - k][right + k] = true;
		else
			break;
		k++;
	}
}
extern inline void _search(int pivot) {
	int left = pivot;
	int right = pivot + 1;
	int k = 0;
	while (left - k >= 0 && right + k < N) {
		if (str[left - k] == str[right + k])
			possi[left - k][right + k] = true;
		else
			break;
		k++;
	}
}
int dist[2501];
int main() {
	scanf("%s", str);
	N = strlen(str);
	for (int i = 0; i < N; i++)
		search(i);
	for (int i = 0; i < N-1; i++)
		_search(i);
	int head = 0;
	int tail = 0;
	dist[0] = 1;
	for (int i = 1; i < N; i++) {
		int _min = 987654321;
		for (int j = 0; j <= i; j++) {
			if (possi[j][i]) {
				if (j - 1 < 0) {
					_min = min(_min, 1);
				}
				else
					_min = min(_min, dist[j - 1] + 1);
			}
		}
		dist[i] = _min;
	}

	printf("%d\n", dist[N - 1]);

	return 0;
}