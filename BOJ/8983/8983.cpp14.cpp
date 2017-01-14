#include "bits/stdc++.h"
using namespace std;
int pt[100000];
pair<int,int> arr[100000];
int M, N, L;
int main() {
	cin >> M >> N >> L;
	for (int i = 0; i < M; i++)
		scanf("%d", &pt[i]);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(pt, pt + M);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int r, l, mid;
		int idx = M-1;
		l = 0; r = M - 1;
		while (r >= l) {
			mid = (l + r) / 2;
			if (pt[mid]>arr[i].first) {
				idx = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		int dist = min(abs(pt[idx] - arr[i].first), abs(arr[i].first - pt[max(0, idx - 1)]));
		if (dist + arr[i].second <= L)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}