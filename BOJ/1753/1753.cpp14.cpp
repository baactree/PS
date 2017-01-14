#include "bits/stdc++.h"
using namespace std;
vector<pair<int, int> >Map[20001];
int dist[20001];
int N, M;
priority_queue<pair<int, int> >pq;
int main() {
	scanf("%d%d", &N, &M);
	int st;
	scanf("%d", &st);
	int a, b, d;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &d);
		Map[a].push_back({ b,d });
	}
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < Map[now].size(); i++) {
			int there = Map[now][i].first;
			int there_cost = Map[now][i].second + cost;
			if (dist[there] > there_cost) {
				dist[there] = there_cost;
				pq.push({ -there_cost,there });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] == 0x3f3f3f3f)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}