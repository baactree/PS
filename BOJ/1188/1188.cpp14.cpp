#include "bits/stdc++.h"
using namespace std;
int main() {
	int N, M, ans;
	cin >> N >> M;
	ans = 0;
	while (true) {
		if (N>M)
			N %= M;
		else if (N == M || N == 0){
			printf("%d\n", ans);
			break;
		}
		else{
			M -= N;
			ans += N;
		}
	}
	return 0;
}