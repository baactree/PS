/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int arr[125];
int idx;
int dp[300001];
int n;
int main() {
	memset(dp, 0x3f, sizeof dp);
	scanf("%d", &n);
	idx = 2;
	for (int i = 1;; i++) {
		arr[i] = i*(i + 1)*(i + 2) / 6;
		if (arr[i] > n) {
			idx = i;
			break;
		}
	}
	dp[0] = 0;
	for (int i = 1; i < idx; i++) {
		for (int j = 0; j <= n-arr[i]; j++) {
			dp[j + arr[i]] = min(dp[j + arr[i]], dp[j] + 1);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}