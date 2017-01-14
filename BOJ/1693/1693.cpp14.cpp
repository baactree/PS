#include "bits/stdc++.h"
using namespace std;
int N;
vector<int> Map[100001];
bool trip[100001];
int dp[100001][4];
void search(int here) {
	trip[here] = true;
	for (int i = 0; i < 4; i++)
		dp[here][i] = i + 1;
	for (int i = 0; i < Map[here].size(); i++) {
		int there = Map[here][i];
		if (!trip[there]) {
			search(there);
			dp[here][0] += min(dp[there][1], min(dp[there][2], dp[there][3]));
			dp[here][1] += min(dp[there][0], min(dp[there][2], dp[there][3]));
			dp[here][2] += min(dp[there][0], min(dp[there][1], dp[there][3]));
			dp[here][3] += min(dp[there][0], min(dp[there][1], dp[there][2]));
		}
	}
}
int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	search(1);
	int ans = 1e9;
	for (int i = 0; i < 4; i++)
		ans = min(ans, dp[1][i]);
	printf("%d\n", ans);
	return 0;
}