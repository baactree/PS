#include "bits/stdc++.h"
using namespace std;
int n, m;
int mat[101][101];
int main() {
	memset(mat, 0x3f, sizeof(mat));
	scanf("%d%d", &n, &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == k || j == k)continue;
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
	int min_cnt;
	min_cnt = 0x3f3f3f3f;
	int min_idx;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			cnt += mat[i][j];
		}
		if (min_cnt > cnt) {
			min_cnt = cnt;
			min_idx = i;
		}
	}
	printf("%d\n", min_idx);
	return 0;
}