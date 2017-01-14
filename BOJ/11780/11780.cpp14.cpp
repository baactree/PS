#include "bits/stdc++.h"
using namespace std;
int mat[101][101];
int n, m;
int par[101][101];
stack<int> stac;
void get_path(int st, int fi) {
	if (st == fi || !par[st][fi])
		return;
	int k = par[st][fi];
	get_path(k, fi);
	stac.push(k);
	get_path(st, k);
}
int main() {
	memset(mat, 0x3f, sizeof(mat));
	scanf("%d%d", &n, &m);
	int a, b, d;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		mat[a][b] = min(mat[a][b], d);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (k == i || j == k)continue;
				if (mat[i][j]>mat[i][k] + mat[k][j]) {
					mat[i][j] = mat[i][k] + mat[k][j];
					par[i][j] = k;
				}
			}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				printf("0 "); continue;
			}
			printf("%d ", mat[i][j] == 0x3f3f3f3f ? 0 : mat[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				printf("0\n");
				continue;
			}
			stac.push(j);
			get_path(i,j);
			stac.push(i);
			printf("%d", stac.size());
			while (!stac.empty()) {
				printf(" %d", stac.top());
				stac.pop();
			}
			printf("\n");
		}
	}
	return 0;
}