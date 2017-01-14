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
int main() {
	int N;
	scanf("%d", &N);
	vector<int> arr(N);
	vector<bool> count(1000001);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		count[arr[i]] = true;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			ll sum, cnt;
			sum = cnt = 0;
			for (int k = arr[i]; k <= arr[N - 1]; k += arr[j] - arr[i]) {
				if (!count[k])
					break;
				sum += k;
				cnt++;
			}
			if (cnt >= 3)
				ans = max(ans, sum);
		}
	printf("%lld\n", ans);
	return 0;
}