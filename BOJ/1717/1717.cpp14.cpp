#include "bits/stdc++.h"
using namespace std;
int par[1000001];
int N, M;
int find(int x) {
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}
void _union(int x, int y) {
	x = find(x);
	y = find(y);
	par[y] = x;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		par[i] = i;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) {
			_union(b, c);
		}
		else {
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}