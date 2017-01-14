#include "bits/stdc++.h"
using namespace std;
int N, H;
int down[100000];
int up[100000];
int main() {
	cin >> N >> H;
	for (int i = 0; i < N / 2; i++)
		scanf("%d%d", &down[i], &up[i]);
	N /= 2;
	sort(down, down + N);
	sort(up, up + N);
	int ans = 0x7fffffff;
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		int r, l, mid, temp, temp2;
		l = 0; r = N - 1;
		temp = 0;
		while (r >= l) {
			mid = (r + l) / 2;
			if (down[mid] > i) {
				temp = N - mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		l = 0; r = N - 1;
		temp2 = 0;
		while (r >= l) {
			mid = (r + l) / 2;
			if (up[mid]>H-1-i) {
				temp2 = N - mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		if (ans > temp + temp2) {
			ans = temp + temp2;
			cnt = 1;
		}
		else if (ans == temp + temp2)
			cnt++;
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}