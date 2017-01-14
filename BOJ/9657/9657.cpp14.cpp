#include <iostream>
#include <stdio.h>

using namespace std;
//ture 상근 win false 상근 lose
bool dp[1001];
int main() {
	int N;
	cin >> N;
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;
	dp[4] = true;
	for (int i = 5; i <= N; i++)
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
			dp[i] = true;

	if (dp[N])
		printf("SK\n");
	else
		printf("CY\n");

	return 0;
}