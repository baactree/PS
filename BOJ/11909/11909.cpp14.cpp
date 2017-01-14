#include "bits/stdc++.h"
using namespace std;
int N;
int Map[2][2222];
int dp[2][2222];
int main() {
	cin >> N;
	bool t = 0;
	for (int i = 0; i < N; i++,t=!t) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[t][j]);
			if (i != 0 && j != 0) {
				dp[t][j] = min(dp[!t][j] + max(0, Map[t][j] + 1 - Map[!t][j]),
					dp[t][j - 1] + max(0, Map[t][j] + 1 - Map[t][j - 1]));
				continue;
			}
			if (i == 0 && j!=0) {
				dp[t][j] = dp[t][j-1] + max(0,Map[t][j] + 1 - Map[t][j - 1]);
				continue;
			}
			if (j == 0 && i!=0) {
				dp[t][j] = dp[!t][j] + max(0,Map[t][j] + 1 - Map[!t][j]);
				continue;
			}
		}
	}
	printf("%d\n", dp[!t][N - 1]);
	return 0;
}