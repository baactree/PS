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
ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}
ll lcs(ll a, ll b) {
	return a / gcd(a, b)*b;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", lcs(a, b));
	}
	return 0;
}