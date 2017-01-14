#include "bits/stdc++.h"
using namespace std;
int N, K;
int dp[2][510][510];
pair<int, int> arr[500];
static inline int dist(int i, int j) {
	return abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	memset(dp, 0x3f, sizeof(dp));
	dp[1][0][0] = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < N; j++)
			for (int k = 0; k <= K; k++)
				dp[(i + 1) % 2][j][k] = 0x3f3f3f3f;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < K; k++) {
				dp[(i + 1)%2][i][k] = min(dp[(i + 1)%2][i][k], dp[i%2][j][k] + dist(i, j));
				dp[(i + 1)%2][j][k + 1] = min(dp[(i + 1)%2][j][k + 1], dp[i%2][j][k]);
			}
			dp[(i + 1)%2][i][K] = min(dp[(i + 1)%2][i][K], dp[i%2][j][K] + dist(i, j));
		}
	}
	int ans = 0x7fffffff;
	for (int j = 0; j < N; j++)
		for (int k = 0; k <= K;k++)
			ans = min(dp[(N - 1)%2][j][k] + dist(N - 1, j), ans);
	printf("%d\n", ans);
	return 0;
}