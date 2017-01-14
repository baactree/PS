#include "bits/stdc++.h"
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
bool used[2001][2001];
int main() {
	int N, M;
	cin >> N >> M;
	int ans = 0;
	for (int i = N; i <= M; i++) {
		for (int j = 1; j <= i; j++) {
			int g = gcd(j, i);
			int c = j / g;
			int p = i / g;
			if (!used[c][p]) {
				ans++;
				used[c][p] = true;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}