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
int N;
int matrix[500][2];
int cache[501][501];
int search(int i,int j) {
	int& ret = cache[i][j];
	if (i == j)
		return 0;
	if (ret != -1)
		return ret;
	ret = 2000000000;
	for (int k = i; k < j; k++) {
		ret = min(ret, search(i, k) + search(k + 1, j)
			+ matrix[i][0] * matrix[k][1] * matrix[j][1]);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) 
		scanf("%d%d", &matrix[i][0], &matrix[i][1]);
	printf("%d\n", search(0, N - 1));
	return 0;
}