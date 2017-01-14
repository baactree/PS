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
int in[100001];
int out[100001];
int N;
ll dp[1000001];
int arr[3];
int calc(int a, int b) {
	if (a == b)
		return LINF;
	return abs(a - b);
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &in[i], &out[i]);
	sort(in + 1, in + N + 1);
	sort(out + 1, out + N + 1);
	for (int i = 1; i <= N; i++) {
		dp[i] = LINF;
		for (int k = 1; k <= 3 && i - k >= 0; k++) {
			for (int j = 0; j < k; j++)
				arr[j] = j;
			while (true) {
				ll cost = 0;
				for (int j = 0; j < k; j++)
					cost += calc(in[i - j], out[i - arr[j]]);
				dp[i] = min(dp[i], dp[i - k] + cost);
				if (!next_permutation(arr, arr + k))
					break;
			}
		}
	}
	printf("%lld\n", dp[N]);
	return 0;
}