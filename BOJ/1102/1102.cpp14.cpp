#include "bits/stdc++.h"
using namespace std;
int N;
int Map[16][16];
int P;
char in[17];
int cache[1 << 16];
int search(int state) {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (state&(1 << i))
			cnt++;
	if (cnt >= P)
		return 0;
	int &ret = cache[state];
	if (ret != -1)
		return ret;
	ret = 0x3f3f3f3f;
	for (int i = 0; i < N; i++) {
		if (state&(1 << i))
			continue;
		int min_cost = 0x3f3f3f3f;
		for (int j = 0; j < N; j++)
			if (state&(1 << j) && i!=j)
				min_cost = min(min_cost, Map[j][i]);
		ret = min(ret, search(state | (1 << i)) + min_cost);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	scanf("%s", in);
	cin >> P;
	int state = 0;
	for (int i = 0; i < N; i++)
		if (in[i] == 'Y')
			state |= (1 << i);
	int ans = search(state);
	printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
	return 0;
}