#include "bits/stdc++.h"
using namespace std;
int R, C;
int Map[752][752];
int dp[752][752][4];
// 좌상 우상 좌하 우하
int main() {
	scanf("%d%d", &R, &C);
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			scanf("%1d", &Map[i][j]); 
			if (Map[i][j]) {
				dp[i][j][0] = dp[i - 1][j - 1][0] + Map[i][j];
				dp[i][j][1] = dp[i - 1][j + 1][1] + Map[i][j];
			}
		}
	for (int i = R; i >= 1; i--)
		for (int j = 1; j <= C; j++) {
			if (Map[i][j]) {
				dp[i][j][2] = dp[i + 1][j - 1][2] + Map[i][j];
				dp[i][j][3] = dp[i + 1][j + 1][3] + Map[i][j];
			}
		}
	int ans = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			int temp = min(dp[i][j][2], dp[i][j][3]);
			while (temp) {
				int k = temp * 2 - 2;
				if(i + k <= R)
					if (min(dp[i + k][j][0], dp[i + k][j][1]) >= temp) {
						ans = max(ans, temp);
						break;
					}
				temp--;
			}
		}
	printf("%d\n", ans);
	return 0;
}