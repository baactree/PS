#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll search(ll s0, ll s1, ll x) {
	if (x == 0)
		return s0;
	if (x == 1)
		return s1;
	if (s1 == 0) {
		if (x % 3 == 1)
			return 0;

		return s0;
	}
	if (s0 <= s1)
		return search(s1, s1 - s0, x - 1);
	ll d = s0 - s1;
	ll cnt = s0 / d;
	ll len = (cnt + 1) / 2 * 3;
	if (cnt % 2 == 0)
		cnt--;
	if (x < len) {
		if (x % 3 == 2)
			return d;
		ll group = x / 3;
		if (x % 3 == 0)
			return s0 - group * 2 * d;
		return s0 - (group * 2 + 1)*d;
	}
	ll s02;
	ll s12;
	s02 = s0 - cnt*d - d;
	if (s02 < 0)
		s02 = -s02;
	s12 = d - s02;
	if (s12 < 0)
		s12 = -s12;
	return search(d, s02, x - len + 1);
}
int main() {
	ll s0, s1;
	int n;
	scanf("%lld%lld%d\n", &s0, &s1, &n);
	while (n--) {
		ll x;
		scanf("%lld\n", &x);
		printf("%lld\n", search(s0, s1, x));
	}
	return 0;
}
