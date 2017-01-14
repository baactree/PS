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
#define all(x) x.begin(),x.end()
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int N, K;
int arr[100];
bool dp[200001];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &N, &K);
		int sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		if (K > 400000) {
			printf("FULL\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < N; i++)
			for (int j = sum - arr[i]; j >= 0; j--)
				dp[j + arr[i]] |= dp[j];
		int ans = -1;
		for (int i = (K + 1) / 2; i <= sum; i++)
			if (dp[i]) {
				ans = i;
				break;
			}
		if (ans == -1)
			printf("FULL\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}