#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N, K;
int val[100];
int cache[100][10001];
int search(int idx, int k) {
	if (k == K)
		return 0;
	if (k>K)
		return 987654321;
	if (idx == N)
		return 987654321;
	int &ret = cache[idx][k];
	if (ret != -2)
		return ret;
	ret =search(idx, k + val[idx]) + 1;
	ret = min(ret, search(idx + 1, k));
	return ret;
}
int main() {
	cin >> N >> K;
	for (int i = 0;i<100;i++)
		for (int j = 0;j<10001;j++)
			cache[i][j] = -2;
	for (int i = 0;i<N;i++)
		scanf("%d", &val[i]);
	int ans = search(0, 0);
	if (ans==987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}