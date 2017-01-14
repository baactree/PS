#include "bits/stdc++.h"
using namespace std;
int N, M;
int cache[1000][1000];
int a[1000];
int b[1000];
int search(int idx, int nidx) {
	if (idx == N)
		return 0;
	if (nidx == M)
		return 0x3f3f3f3f;
	int &ret = cache[idx][nidx];
	if (ret != -1)
		return ret;
	ret = search(idx, nidx + 1);
	ret = min(ret, search(idx + 1, nidx + 1) + abs(a[idx] - b[nidx]));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &b[i]);
	sort(a, a + N);
	sort(b, b + M);
	if (N > M) {
		swap(N, M);
		swap(a, b);
	}
	printf("%d\n", search(0, 0));
	return 0;
}