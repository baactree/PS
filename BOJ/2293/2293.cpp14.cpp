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
using namespace std;
int N, K;
int dp[2][10001];
int val[100];
int main() {
	cin >> N>>K;
	for (int i = 0; i < N; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= K; j++) {
			if (j == 0)
				dp[i%2][j] = 1;
			else if (i - 1 >= 0 && j - val[i] >= 0)
				dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - val[i]];
			else if (i - 1 < 0&&j-val[i]>=0)
				dp[i % 2][j] = dp[i % 2][j - val[i]];
			else if (j - val[i] < 0&&i-1>=0)
				dp[i % 2][j] = dp[(i - 1) % 2][j];
	}
	printf("%d\n", dp[(N-1)%2][K]);
	return 0;
}