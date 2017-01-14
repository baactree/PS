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
ll cache[65][10];
ll search(int idx, int num) {
	if (idx == 0)
		return 1;
	ll &ret = cache[idx][num];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = num; i < 10; i++)
		ret += search(idx - 1, i);
	return ret;
}
int main() {
	int tc;
	cin >> tc;
	memset(cache, -1, sizeof(cache));
	while (tc--) {
		int N;
		scanf("%d", &N);
		printf("%lld\n", search(N,0));
	}
	return 0;
}