#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
int N, M, K;
ll tree[1000001];
int arr[1000001];
void add(int pos, int val) {
	while (pos < N+1) {
		tree[pos] += val;
		pos += (pos&-pos);
	}
}
ll sum(int pos) {
	ll ret = 0;
	while (pos > 0) {
		ret += tree[pos];
		pos &= (pos - 1);
	}
	return ret;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		add(i, arr[i]);
	}
	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			add(b, -arr[b]);
			add(b, c);
			arr[b] = c;
		}
		else {
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}
	return 0;
}