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
int cache[5001];
int solve(int n) {
	if (n < 0)
		return INF;
	if (n == 0)
		return 0;
	int &ret = cache[n];
	if (ret != -1)
		return ret;
	ret = solve(n - 5) + 1;
	ret = min(ret, solve(n - 3) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int N;
	scanf("%d", &N);
	int ans = solve(N);
	printf("%d\n", ans >= INF-3 ? -1 : ans);
	return 0;
}