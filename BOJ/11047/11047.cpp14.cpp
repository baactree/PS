#include "bits/stdc++.h"
using namespace std;
int N, K;
int arr[10];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int ans = 0;
	int idx = N - 1;
	while (K != 0) {
		ans += K / arr[idx];
		K = K%arr[idx];
		idx--;
	}
	printf("%d\n", ans);
	return 0;
}