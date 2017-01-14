/////////////////////////////////////////////////////
#ifdef _DEBUG
#include "bits_stdc++.h"
#else
#include "bits/stdc++.h"
#endif
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
typedef vector<int>::iterator It;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int dp[10001];
int main() {
	int N;
	scanf("%d", &N);
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= N; i += 2) {
		for (int j = 0; j < i; j += 2) {
			dp[i] += ((ll)dp[j] * dp[i - 2 - j]) % 987654321;
			dp[i] %= 987654321;
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}