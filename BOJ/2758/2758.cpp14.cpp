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
int N, M;
ll cache[11][2001];
ll solve(int idx, int now) {
	if (idx == 0)
		return 1;
	if (now == 0)
		return 0;
	ll &ret = cache[idx][now];
	if (ret != -1)
		return ret;
	ret = solve(idx, now - 1);
	ret += solve(idx - 1, now / 2);
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	memset(cache, -1, sizeof(cache));
	while (Case--) {
		scanf("%d%d", &N, &M);
		printf("%lld\n", solve(N, M));
	}
	return 0;
}