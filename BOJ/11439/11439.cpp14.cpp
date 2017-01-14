#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
typedef long long int ll;
ll N, K, M;
ll search(ll t, ll k) {
	ll ret=0;
	while (t > 0) {
		ret += t / k;
		t /= k;
	}
	return ret;
}
ll _pow(ll a, ll b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a%M;
	if (b % 2 == 0) {
		ll temp = _pow(a, b / 2);
		return (temp*temp) % M;
	}
	return (_pow(a, b - 1)*a) % M;
}
bool check[4000001];
int main()
{
	cin >> N >> K >> M;
	ll ans = 1;
	for (ll i = 2; i <= N; i++) {
		if (!check[i]) {
			for (ll j = i * 2; j <= N; j += i)
				check[j] = true;
			ll k = search(N, i) - search(N - K, i) - search(K, i);
			ans = (ans*_pow(i, k))%M;
		}
	}
	printf("%lld\n", ans);
	return 0;
}