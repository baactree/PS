#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		ans += (i*(i + 1)) + i*(i + 1) / 2;
	}
	printf("%d\n", ans);
}