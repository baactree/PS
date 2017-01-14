#include "bits/stdc++.h"
using namespace std;
int N, M;
int price_p[50];
int price_s[50];
int cache[50][200];
int search(int idx, int sum) {
	if (sum >= N)
		return 0;
	if (idx == M)
		return 0x3f3f3f3f;
	int &ret = cache[idx][sum];
	if (ret != -1)
		return ret;
	ret = 0x7fffffff;
	for (int i = 0; i * 6 + sum <= N + 6; i++) 
		ret = min(ret, search(idx + 1, sum + i * 6) + i*price_s[idx]);
	for (int i = 0; i + sum <= N; i++)
		ret = min(ret, search(idx + 1, sum + i) + i*price_p[idx]);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		scanf("%d%d", &price_s[i], &price_p[i]);
	printf("%d\n", search(0, 0));
	return 0;
}