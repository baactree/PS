#include "bits/stdc++.h"
using namespace std;
#define SIZE 100000
#define LGN 16
int N, M;
int RMQ[SIZE + 1][LGN + 1], depth[SIZE + 1];
int dist_max[SIZE + 1][LGN + 1];
int dist_min[SIZE + 1][LGN + 1];
bool trip[SIZE + 1];
vector<pair<int, int> > Map[SIZE + 1];
void dfs(int here) {
	trip[here] = true;
	for (int i = 0; i < Map[here].size(); i++) {
		int there = Map[here][i].first;
		int cost = Map[here][i].second;
		if (trip[there])
			continue;
		depth[there] = depth[here] + 1;
		RMQ[there][0] = here;
		dist_max[there][0] = cost;
		dist_min[there][0] = cost;
		for (int i = 1; i <= LGN; i++) {
			dist_max[there][i] = max(dist_max[there][i - 1], dist_max[RMQ[there][i - 1]][i - 1]);
			dist_min[there][i] = min(dist_min[there][i - 1], dist_min[RMQ[there][i - 1]][i - 1]);
			RMQ[there][i] = RMQ[RMQ[there][i - 1]][i - 1];
		}
		dfs(there);
	}
}
pair<int, int> lca(int x, int y) {
	pair<int, int> ret = make_pair(0x3fffffff, 0);
	if (depth[x] < depth[y])swap(x, y);
	for (int i = LGN; i >= 0; i--)
		if ((1 << i) <= depth[x] - depth[y]) {
			ret.first = min(ret.first, dist_min[x][i]);
			ret.second = max(ret.second, dist_max[x][i]);
			x = RMQ[x][i];
		}
	if (x == y)
		return ret;
	for (int i = LGN; i >= 0; i--)
		if (RMQ[x][i] != RMQ[y][i]) {
			ret.first = min(ret.first, min(dist_min[x][i], dist_min[y][i]));
			ret.second = max(ret.second, max(dist_max[x][i], dist_max[y][i]));
			x = RMQ[x][i], y = RMQ[y][i];
		}
	ret.first = min(ret.first, min(dist_min[x][0], dist_min[y][0]));
	ret.second = max(ret.second, max(dist_max[x][0], dist_max[y][0]));
	return ret;
}
int main() {
	scanf("%d", &N);
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &a, &b, &c);
		Map[a].push_back(make_pair(b, c));
		Map[b].push_back(make_pair(a, c));
	}
	dfs(1);
	scanf("%d", &M);
	pair<int, int> ans;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		ans = lca(a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}