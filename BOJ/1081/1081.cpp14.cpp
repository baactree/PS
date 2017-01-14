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
ll search(ll n, ll k) {
	ll ret = 0;
	for (ll i = 0, j = 1; j <= n; j *= 10, i++) {
		ll temp = (n / j) % 10;
		if (k < temp)
			ret += j;
		else if (k == temp)
			ret += n%j + 1;
		ret += temp*i*(j / 10);
	}
	return ret;
}
int main() {
	ll l, u;
	cin >> l >> u;
	l--;
	ll ans = 0;
	for (int i = 1; i < 10; i++) 
		ans += (search(u, i) - search(l, i))*i;
	printf("%lld\n", ans);
	return 0;
}