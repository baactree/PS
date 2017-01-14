#include "bits/stdc++.h"
using namespace std;
int cnt[101];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cnt, 0, sizeof cnt);
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i ++ ) {
			for (int j = i; j <= N; j += i)
				cnt[j]++;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if (cnt[i] & 1)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}