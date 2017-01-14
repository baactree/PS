#include "bits/stdc++.h"
using namespace std;
int Map[51][51];
int dist[51];
int N;
vector<int> ans;
int main() {
	cin >> N;
	int a, b;
	memset(Map, 0x3f, sizeof(Map));
	while (true) {
		scanf("%d%d", &a, &b);
		if (a == -1 && b == -1)
			break;
		Map[a][b] = 1;
		Map[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if(!((i==j)||(i==k)||(k==j)))
					Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
	int ans_dist = 0x3f3f3f3f;
	for (int i = 1; i <= N; i++) {
		int max_dist = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			max_dist = max(max_dist, Map[i][j]);
		}
		dist[i] = max_dist;
		ans_dist = min(ans_dist, max_dist);
	}
	for (int i = 1; i <= N; i++)
		if (dist[i] == ans_dist)
			ans.push_back(i);
	printf("%d %d\n", ans_dist, ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}