#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <deque>
#include <stack>
using namespace std;
#define INF 10000000
int Map[101][101];
int N,M;
int main() {
	cin >> N >> M;
	int a, b, d;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			Map[i][j] = INF;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &d);
		if(Map[a][b]>d)
			Map[a][b] = d;
	}

	
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++) {
			if (i == k)
				continue;
			for (int j = 1; j <= N; j++) {
				if (j == k)
					continue;
				if (Map[i][j]>Map[i][k] + Map[k][j])
					Map[i][j] = Map[i][k] + Map[k][j];
			}
		}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (Map[i][j] != INF&&i!=j)
				printf("%d ", Map[i][j]);
			else
				printf("0 ");
		printf("\n");
	}

	return 0;
}