#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
typedef long long ll;
int N;
int arr[100000];
int arr2[100000];
int dp[2][2];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < N - 1; i++)
		scanf("%d", &arr2[i]);
	dp[0][0] = 1;
	bool t = false;
	for (int i = 0; i < N; i++,t=!t) {
		dp[!t][0] = ((dp[t][0] * (ll)arr[i])%mod + (dp[t][1] * (ll)arr[i])%mod)%mod;
		if (i > 0) {
			dp[!t][0] = (dp[!t][0] + (dp[t][1] * (ll)(arr2[i - 1]-1))%mod+(dp[t][0] * (ll)arr2[i - 1])%mod)%mod;
		}
		dp[!t][1] = ((dp[t][0] * (ll)arr2[i])%mod + (dp[t][1] * (ll)arr2[i])%mod)%mod;
		
	}
	printf("%d\n", (dp[t][0] + dp[t][1])%mod);
	return 0;
}
