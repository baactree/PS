#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
int main() {
	unsigned long long int dp[70];
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 70; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		cin >> N;
		printf("%llu\n", dp[N]);
	}
	return 0;
}