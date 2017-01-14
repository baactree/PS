#include "bits/stdc++.h"
using namespace std;
#define X 45678
int dp[3];
int main() {
	int N;
	cin >> N;
	dp[1] = 5;
	for (int i = 2; i <= N; i++)
		dp[i % 3] = ((((dp[(i - 1) % 3] + i)%X + i)%X + i)%X + 1)%X;
	printf("%d\n", dp[N % 3]);
	return 0;
}