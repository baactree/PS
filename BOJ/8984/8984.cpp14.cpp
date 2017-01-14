#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
struct dat {
	int t, d, tidx, didx;
};
dat line[100000];
ll dp_t[100000];
ll dp_d[100000];
int N, L;
bool cmp(const dat &a, const dat &b) {
	if (a.t == b.t)
		return a.d < b.d;
	return a.t < b.t;
}
bool cmp2(const dat &a, const dat &b) {
	return a.d < b.d;
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		scanf("%d%d", &line[i].t, &line[i].d);
	sort(line, line + N,cmp2);
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (i != 0 && line[i].d != line[i - 1].d) {
			line[i].didx = ++idx;
			continue;
		}
		line[i].didx = idx;
	}
	sort(line, line + N, cmp);
	idx = 0;
	for (int i = 0; i < N; i++) {
		if (i != 0 && line[i].t != line[i - 1].t) {
			line[i].tidx = ++idx;
			continue;
		}
		line[i].tidx = idx;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		int len = abs(line[i].d - line[i].t) + L;
		ll D, T;
		D = len + dp_t[line[i].tidx];
		T = len + dp_d[line[i].didx];
		dp_d[line[i].didx] = max(dp_d[line[i].didx], D);
		dp_t[line[i].tidx] = max(dp_t[line[i].tidx], T);
		ans = max(ans, max(D,T));
	}
	printf("%lld\n", ans);
	return 0;
}