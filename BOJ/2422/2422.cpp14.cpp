#include "bits/stdc++.h"
using namespace std;
int N, M;
bool possi[201][201];
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		possi[a][b] = possi[b][a] = true;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			for (int k = j + 1; k <= N; k++) {
				if (possi[i][j])continue;
				if (possi[j][k])continue;
				if (possi[k][i])continue;
				ans++;
			}
	printf("%d\n", ans);
	return 0;
}