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
#define INF 987654321
int Map[401][401];
int V, E;
int main() {
	cin >> V >> E;
	int a, b, d;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			Map[i][j] = INF;
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &a, &b, &d);
		Map[a][b] = d;
	}
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);

	int ans = 987654321;
	for (int k = 1; k <= V; k++)
		ans = min(ans, Map[k][k]);
	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}