#include "bits/stdc++.h"
using namespace std;
int N,S;
int arr[40];
int le[1 << 20], ri[1 << 20];
typedef long long ll;
bool cmp(const int&a, const int&b) {
	return a > b;
}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int mid = N / 2;
	N -= mid;
	for (int i = 0; i < (1 << N); i++)
		for (int j = 0; j < N; j++)
			if (i&(1 << j))
				le[i] += arr[j];
	for (int i = 0; i < (1 << mid); i++)
		for (int j = 0; j < mid; j++)
			if (i & (1 << j))
				ri[i] += arr[j+N];
	N = (1 << N);
	mid = (1 << mid);
	sort(le, le + N);
	sort(ri, ri + mid,cmp);
	ll ans = 0;
	for (int i = 0, j = 0; i < N&&j < mid;) {
		if (le[i] + ri[j] == S) {
			ll cnt_le = 1;
			ll cnt_ri = 1;
			i++; j++;
			while (i < N&&le[i] == le[i - 1]) {
				cnt_le++;
				i++;
			}
			while (j < mid&&ri[j] == ri[j - 1]) {
				cnt_ri++;
				j++;
			}
			ans += cnt_le*cnt_ri;
			continue;
		}
		if (le[i] + ri[j] < S)
			i++;
		else
			j++;
	}
	if (S == 0)
		ans--;
	printf("%lld\n", ans);
	return 0;
}