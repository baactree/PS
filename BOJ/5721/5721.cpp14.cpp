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
int row[100010];
int col[100010];
vector<int> dp;
int main() {
	while (true) {
		int N, M;
		scanf("%d%d", &N, &M);
		if (N == M&&N == 0)
			break;
		for (int i = 0; i < N; i++) {
			dp = vector<int>(M + 2, 0);
			for (int j = 0; j < M; j++)
				scanf("%d", &col[j]);
			for (int j = 0; j < M; j++) {
				dp[j + 1] = max(dp[j + 1], dp[j]);
				dp[j + 2] = max(dp[j + 2], dp[j] + col[j]);
			}
			row[i] = max(dp[M],dp[M+1]);
		}
		dp = vector<int>(N + 2, 0);
		for (int i = 0; i < N; i++) {
			dp[i + 1] = max(dp[i + 1], dp[i]);
			dp[i + 2] = max(dp[i + 2], dp[i] + row[i]);
		}
		printf("%d\n", max(dp[N], dp[N + 1]));
	}
	return 0;
}