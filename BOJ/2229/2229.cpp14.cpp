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
int N;
int score[1001];
int cache[1001];
int Max_score[1001][1001];
int Min_score[1001][1001];
int search(int n) {
	int &ret = cache[n];
	if (ret != -1)
		return ret;
	if (n == 0)
		return ret=0;
	for (int k = 1; k <= n; k++) {
		ret = max(ret, search(n - k) + Max_score[n-k+1][n] - Min_score[n-k+1][n]);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N;i++)
		scanf("%d", &score[i]);
	for (int i = 1; i <= N; i++) {
		int Max = -1;
		for (int j = i; j <= N; j++) {
			Max = max(Max, score[j]);
			Max_score[i][j] = Max;
		}
	}
	for (int i = 1; i <= N; i++) {
		int Min = 987654321;
		for (int j = i; j <= N; j++) {
			Min = min(Min, score[j]);
			Min_score[i][j] = Min;
		}
	}
	printf("%d\n", search(N));
	return 0;
}