#include "bits/stdc++.h"
using namespace std;
int N, M;
int arr[500000];
static inline bool search(int num) {
	int idx = lower_bound(arr, arr + N, num) - arr;
	if (arr[idx] == num)
		return true;
	return false;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	scanf("%d", &M);
	int in;
	for (int i = 0; i < M; i++) {
		scanf("%d", &in);
		printf("%d ", search(in));
	}
	return 0;
}