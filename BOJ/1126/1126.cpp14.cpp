#include "bits/stdc++.h"
using namespace std;
#define shift 500000
int N;
int arr[50];
int dp[2][shift * 2 + 1];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	dp[0][shift] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < shift * 2 + 1; j++)
			dp[(i + 1) % 2][j] = -1;
		for (int j = 0; j < shift * 2 + 1; j++) {
			if (dp[i % 2][j] != -1) {
				dp[(i + 1) % 2][j + arr[i]] = max(dp[(i + 1) % 2][j + arr[i]], dp[i % 2][j] + arr[i]);
				dp[(i + 1) % 2][j - arr[i]] = max(dp[(i + 1) % 2][j - arr[i]], dp[i % 2][j] + arr[i]);
				dp[(i + 1) % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j]);
			}
		}
	}
	printf("%d\n", dp[N % 2][shift] == 0 ? -1 : dp[N % 2][shift] / 2);
	return 0;
}
