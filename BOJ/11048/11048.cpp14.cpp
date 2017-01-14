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

using namespace std;
int N, M;
int Map[1000][1000];
int cache[1000][1000];

int search(int x, int y) {
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
	if (x == 0 && y == 0)
		return ret=Map[0][0];
	if (x == 0)
		return ret=search(x, y - 1) + Map[x][y];
	if (y == 0)
		return ret=search(x - 1, y) + Map[x][y];
	ret = max(ret, search(x - 1, y - 1) + Map[x][y]);
	ret = max(ret, search(x - 1, y) + Map[x][y]);
	ret = max(ret, search(x, y - 1) + Map[x][y]);
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &Map[i][j]);
	printf("%d\n", search(N - 1, M - 1));
	return 0;
}




