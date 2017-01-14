#include "bits/stdc++.h"
using namespace std;
int N, K;
int arr[50];
typedef long long ll;
ll dp[10][500001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	cin >> K;
	dp[0][0] = 1;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int sum = 0; sum <= 500000; sum++)
			if (sum > arr[i])
				ans += dp[K - 1][sum];
		for (int j = K-2; j >= 0; j--) {
			for (int sum = 0; sum <= 500000; sum++) {
				if(dp[j][sum]!=0)
					dp[j + 1][sum + arr[i]] += dp[j][sum];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
