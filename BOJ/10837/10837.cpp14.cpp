#include "bits/stdc++.h"
using namespace std;
int N, M, K;
bool dp[1001][1001];
int main() {
	cin >> K;
	dp[0][0] = true;
	for (int i = 0; i <= K; i++)
		for (int j = 0; j <= K; j++) {
			if (i == 0 && j == 0)
				continue;
			int pi = max(0, i - 1);
			int pj = max(0, j - 1);
			int round;
			int min_score;
			if (dp[pi][j]) {
				round = max(pi, j);
				min_score = min(pi, j);
				if (K - round + min_score >= round)
					dp[i][j] = true;
			}
			if (dp[i][pj]) {
				round = max(i, pj);
				min_score = min(i, pj);
				if (i < pj) {
					if (i + K - round < pj + 1)
						continue;
				}
				else
					if (pj + K - round + 1 < i)
						continue;
				dp[i][j] = true;
			}
		}
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &N, &M);
		if (dp[N][M])
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}