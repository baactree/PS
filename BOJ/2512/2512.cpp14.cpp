#include "bits/stdc++.h"
using namespace std;
int arr[10000];
int N,M;
bool possi(int data) {
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += min(data, arr[i]);
	if (sum <= M)
		return true;
	return false;
}
int main() {
	cin >> N;
	int sum = 0;
	int max_value = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		max_value = max(max_value, arr[i]);
	}
	cin >> M;
	if (sum <= M) {
		printf("%d\n", max_value);
	}
	else {
		int r, l, mid;
		r = M, l = 0;
		int ans;
		while (r >= l) {
			mid = (r + l) / 2;
			if (possi(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}