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
ll sum(ll x) {
	return x*(x + 1) / 2;
}
int main() {
	ll N, M;
	scanf("%lld%lld", &N, &M);
	if (N > M)
		swap(N, M);
	if (M < 0) {
		printf("%lld\n", -(sum(-N) - sum(-M) + -M));
	}
	else if (N < 0) {
		printf("%lld\n", sum(M) - sum(-N));
	}
	else {
		printf("%lld\n", sum(M) - sum(N) + N);
	}
	return 0;
}