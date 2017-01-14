#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
#define INF 987654321
int N;
int Map[1000];
int cache[1000];
int search(int idx) {
	if (idx >= N-1)
		return 0;
	int &ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 1; i <= Map[idx]; i++)
		ret = min(ret, search(idx + i) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &Map[i]);
	int ans = search(0);
	printf("%d\n", ans>=INF?-1:ans);
	return 0;
}