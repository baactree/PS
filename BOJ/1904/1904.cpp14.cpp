#include "bits/stdc++.h"
using namespace std;
int N;
int dp[1000001];
#define X 15746
int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % X;
	printf("%d\n", dp[N]);
	return 0;
}