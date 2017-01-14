#include "bits/stdc++.h"
using namespace std;
int N, K;
int arr[10];
int in;
int dp[360];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	dp[0] = true;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 360; k++)
			for (int j = 0; j < 360; j++)
				if (dp[k])
					dp[(k + j*arr[i]) % 360] = true;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &in);
		if (dp[in])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}