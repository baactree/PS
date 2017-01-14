#include "bits/stdc++.h"
using namespace std;
int Map[401][401];
int N, K, S;
int main() {
	cin >> N >> K;
	int a, b;
	memset(Map, 0x3f, sizeof(Map));
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		Map[a][b] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
	cin >> S;
	for (int i = 0; i < S; i++) {
		scanf("%d%d", &a, &b);
		if (Map[a][b] != 0x3f3f3f3f)
			printf("-1\n");
		else if (Map[b][a] != 0x3f3f3f3f)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}