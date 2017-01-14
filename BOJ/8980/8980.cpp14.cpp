#include "bits/stdc++.h"
using namespace std;
struct dat {
	int a, b, d;
};
int N, C, M;
dat arr[10000];
int truck[2001];
bool cmp(const dat &a, const dat &b) {
	return a.b < b.b;
}
int main() {
	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) 
		scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].d);
	sort(arr, arr + M, cmp);
	int ans = 0;
	int vol = 0;
	for (int i = 0; i < M; i++) {
		vol = 0;
		for (int j = arr[i].a; j < arr[i].b; j++)
			vol = max(vol, truck[j]);
		int temp = min(arr[i].d, C - vol);
		for (int j = arr[i].a; j < arr[i].b; j++)
			truck[j] += temp;
		ans += temp;
	}
	printf("%d\n", ans);
	return 0;
}