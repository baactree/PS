#include "bits/stdc++.h"
using namespace std;
int dp[1001][1001];
vector<int> ans;
int main() {
	int N, M;
	cin >> N >> M;
	int input;
	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &input);
			if (input) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	printf("%d\n", ans*ans);
	return 0;
}