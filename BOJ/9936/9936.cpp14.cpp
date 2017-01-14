#include "bits/stdc++.h"
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
int N, K;
long long Map[1000][3];
long long cache[1000][1000][1 << 3];
long long search(int idx, int k, int state) {
	if (idx == N) {
		if (state == 0&&k==K)
			return 0;
		return -inf;
	}
	if (k == K)
		return 0;
	if (k > K)
		return -inf;
	long long &ret = cache[idx][k][state];
	if (ret != inf)
		return ret;
	ret = search(idx + 1, k, 0);
	for (int i = 0; i < 3; i++)
		if (!(state&(1 << i)))
			ret = max(ret, search(idx + 1, k + 1, 1 << i) + Map[idx][i] + Map[idx + 1][i]);
	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += Map[idx][i] + Map[idx + 1][i];
	for (int i = 0; i < 3; i++)
		if (!(state&~(1 << i)))
			ret = max(ret, search(idx + 1, k + 2, 7 & ~(1 << i)) + sum - Map[idx][i] - Map[idx + 1][i]);
	if (!(state & 1) && !(state & 2))
		ret = max(ret, search(idx + 1, k + 1, 0) + Map[idx][0] + Map[idx][1]);
	if (!(state & 2) && !(state & 4))
		ret = max(ret, search(idx + 1, k + 1, 0) + Map[idx][1] + Map[idx][2]);
	sum = 0;
	for (int i = 0; i < 3; i++)
		sum += Map[idx][i];
	if (!state) {
		ret = max(ret, search(idx + 1, k + 2, 1) + Map[idx + 1][0] + sum);
		ret = max(ret, search(idx + 1, k + 2, 4) + Map[idx + 1][2] + sum);
	}
	return ret;
}
int main() {
	memset(cache, 0x3f, sizeof(cache));
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%lld", &Map[i][j]);
	printf("%lld\n", search(0, 0, 0));
	return 0;
}