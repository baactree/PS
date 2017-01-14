#include "bits/stdc++.h"
using namespace std;
int N;
int le[2000], ri[2000];
int cache[2000][2000];
int search(int left, int right) {
	if (left == N || right == N)
		return 0;
	int &ret = cache[left][right];
	if (ret != -1)
		return ret;
	ret = 0;
	if (ri[right] < le[left])
		ret = search(left, right + 1) + ri[right];
	ret = max(ret, search(left + 1, right + 1));
	ret = max(ret, search(left + 1, right));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &le[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &ri[i]);
	printf("%d\n", search(0, 0));
	return 0;
}