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
int N, M;
int arr[100];
int cache[100][50][2];
int search(int n, int m,bool upper) {
	if (n == N&&m == M)
		return 0;
	if (n == N)
		return -987654321;
	int& ret=cache[n][m][upper];
	if (ret != -1)
		return ret;
	if (upper == false) {
		ret = search(n + 1, m+1, true) + arr[n];
		ret = max(ret, search(n + 1, m, false));
	}
	else {
		ret = search(n + 1, m, true) + arr[n];
		ret = max(ret, search(n + 1, m, false));
	}
	return ret;
	
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", search(0, 0,0));
	return 0;
}