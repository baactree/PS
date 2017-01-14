#include "bits/stdc++.h"
using namespace std;
int n;
int mat[21][21];
bool use[21][21];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &mat[i][j]);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == k || j == k)
					continue;
				if (mat[i][j] > mat[i][k] + mat[k][j]) {
					printf("-1\n");
					return 0;
				}
				if (mat[i][j] == mat[i][k] + mat[k][j]) {
					use[i][j] = true;
				}
			}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if(!use[i][j])
				cnt += mat[i][j];
	printf("%d\n", cnt);
	return 0;
}