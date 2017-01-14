#include "bits/stdc++.h"
using namespace std;
int N;
int arr[1000000];
int dp[1000001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		dp[arr[i]] = dp[arr[i] - 1] + 1;
		ans = max(ans, dp[arr[i]]);
	}
	printf("%d\n", N - ans);
	return 0;
}