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
int N, S, M;
int dist[100];
int cache[100][1001];
int search(int idx, int vol) {
	if (vol < 0)
		return -1;
	if (vol > M)
		return -1;
	if (idx == N)
		return vol;
	int& ret = cache[idx][vol];
	if (ret != -2)
		return ret;
	ret = search(idx + 1, vol - dist[idx]);
	ret = max(ret, search(idx + 1, vol + dist[idx]));
	return ret;
}
int main(){
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 1001; j++)
			cache[i][j] = -2;
	scanf("%d%d%d", &N, &S, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &dist[i]);
	printf("%d\n", search(0,S));
	return 0;
}