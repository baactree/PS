#include "bits/stdc++.h"
using namespace std;
int n, m, w;
vector<pair<int, int> >edge[501];
int dist[501];
int cnt[501];
void init() {
	memset(dist, 0x3f, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < 501; i++)
		edge[i].clear();
}
bool spfa() {
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < edge[now].size(); i++) {
			int there = edge[now][i].first;
			int cost = edge[now][i].second;
			if (dist[there] > dist[now] + cost) {
				dist[there] = dist[now] + cost;
				cnt[there]++;
				if (cnt[there] == n)
					return true;
				q.push(there);
			}
		}
	}
	return dist[1] < 0;
}
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		init();
		scanf("%d%d%d", &n, &m, &w);
		int a, b, d;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &d);
			edge[a].push_back({ b,d });
			edge[b].push_back({ a,d });
		}
		for (int i = 0; i < w; i++) {
			scanf("%d%d%d", &a, &b, &d);
			edge[a].push_back({ b,-d });
		}
		if (spfa())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}