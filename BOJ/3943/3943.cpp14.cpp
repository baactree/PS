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
unordered_map<int, int> cache;
int dfs(int n) {
	if (n == 1)
		return cache[n] = 1;
	if (cache.count(n) != 0)
		return cache[n];
	int ret;
	if (n & 1) {
		ret = dfs(n * 3 + 1);
	}
	else
		ret = dfs(n / 2);
	return cache[n] = max(n, ret);
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		scanf("%d", &N);
		printf("%d\n", dfs(N));
	}
	return 0;
}