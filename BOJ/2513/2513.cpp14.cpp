#include "bits/stdc++.h"
using namespace std;
int N, K, S;
int Map[100001];
int main() {
	cin >> N >> K >> S;
	int a, b;
	int le = 0x7fffffff;
	int ri = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		Map[a] = b;
		le = min(le, a);
		ri = max(ri, a);
	}
	int ans = 0;
	int vol = 0;
	int st = le;
	for (int i = le; i < S; i++) {
		while (vol + Map[i] > K) {
			Map[i] = Map[i] - (K - vol);
			ans += abs(S - st) * 2;
			vol = 0;
			st = i;
		}
		vol += Map[i];
	}
	if (vol != 0)
		ans += abs(S - st) * 2;
	vol = 0;
	st = ri;
	for (int i = ri; i >= S; i--) {
		while (vol + Map[i] > K) {
			Map[i] = Map[i] - (K - vol);
			ans += abs(S - st) * 2;
			vol = 0;
			st = i;
		}
		vol += Map[i];
	}
	if (vol != 0)
		ans += abs(S - st) * 2;
	printf("%d\n", ans);
	return 0;
}