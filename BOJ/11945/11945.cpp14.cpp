#include "bits/stdc++.h"
using namespace std;
int Map[10][10];
int N, M;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &Map[i][j]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d", Map[i][M - 1 - j]);
		printf("\n");
	}
	return 0;
}