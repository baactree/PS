#include "bits/stdc++.h"
using namespace std;
const int INF = 100000001;
int N, M;
vector<pair<int, int> >Map[801];
int dist[801];
priority_queue<pair<int, int> >pq;
int dijk(int st, int fi) {
	fill(dist, dist + 1 + N, INF);
	pq.push({ 0,st });
	dist[st] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < Map[now].size(); i++) {
			int there = Map[now][i].first;
			int there_cost = Map[now][i].second;
			if (dist[there] > there_cost + cost) {
				dist[there] = there_cost + cost;
				pq.push({ -(there_cost + cost),there });
			}
		}
	}
	return dist[fi];
}
int main() {
	scanf("%d%d", &N, &M);
	int a, b, d;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &d);
		Map[a].push_back({ b,d });
		Map[b].push_back({ a,d });
	}
	int t1, t2;
	scanf("%d%d", &t1, &t2);
	int ans = dijk(1, t1) + dijk(t1, t2) + dijk(t2, N);
	ans = min(ans, dijk(1, t2) + dijk(t2, t1) + dijk(t1, N));
	printf("%d\n", ans >= INF ? -1 : ans);
	return 0;
}