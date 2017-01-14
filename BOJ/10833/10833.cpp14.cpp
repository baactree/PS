#include "bits/stdc++.h"
using namespace std;
int N;
int main() {
	int ans = 0;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		ans += b%a;
	}
	printf("%d\n", ans);
	return 0;
}