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
ll dp[88];
ll k;
int main() {
	dp[0] = dp[1] = 1;
	for (int i = 2; i < 88; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	scanf("%lld", &k);
	bool flag = false;
	for (int i = 87; i > 0; i--) {
		if (dp[i + 1] > k&&k >= dp[i]) {
			flag = true;
			printf("1");
			k -= dp[i];
		}
		else if (flag)
			printf("0");
	}
	printf("\n");
	return 0;
}