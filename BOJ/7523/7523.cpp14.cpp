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
int main() {
	int Case;
	cin >> Case;
	for (int tc = 1; tc <= Case; tc++) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		bool nf, mf;
		nf = mf = true;
		if (n < 0) {
			nf = false;
			n = -n;
		}
		if (m < 0) {
			mf = false;
			m = -m;
		}
		ll N, M;
		N = n*(n + 1) / 2;
		M = m*(m + 1) / 2;
		printf("Scenario #%d:\n",tc);
		if (nf&&mf) 
			printf("%lld\n", M - N + n);
		if (!nf&&mf)
			printf("%lld\n", M - N);
		if (!nf && !mf)
			printf("%lld\n", -(N - M + m));
		printf("\n");
	}
	return 0;
}