#include "bits/stdc++.h"
using namespace std;
#define INF 0x3f3f3f3f
int N, T;
vector<pair<int, int> > Map[50002];
int dist[50002];
vector<pair<int, int> > y[200001];
pair<int, int> arr[50002];
priority_queue<pair<int, int> >pq;
void RTE() {
	RTE();
	RTE();
}
int main() {
	cin >> N >> T;
	if (!(1 <= N&&N <= 50000))
		RTE();
	if (!(1 <= T&&T <= 200000))
		RTE();
	y[0].push_back({ 0, 0 });
	arr[0] = make_pair(0, 0);
	int a, b;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &a, &b);
		if (!(0 <= a&&a <= 1000000))
			RTE();
		if (!(0 <= b&&b <= T))
			RTE();
		arr[i] = make_pair(a, b);
		y[b].push_back({ a,i });
	}
	for (int i = 0; i <= T; i++)
		if (!y[i].empty())
			sort(y[i].begin(), y[i].end());
	for (int i = 0; i <= T; i++) {
		for (int j = 0; j < y[i].size(); j++) {
			int from = y[i][j].second;
			for (int dy = -2; dy <= 2; dy++) {
				if (i + dy<0 || i + dy>T)
					continue;
				if (y[i + dy].empty())
					continue;
				for (int dx = -2; dx <= 2; dx++) {
					if (dy == 0 && dx == 0)
						continue;
					int nx = y[i][j].first + dx;
					int l, r, mid, to;
					to = INF;
					l = 0; r = (int)y[i + dy].size() - 1;
					while (r >= l) {
						mid = (r + l) / 2;
						if (y[i + dy][mid].first >= nx) {
							to = y[i + dy][mid].second;
							r = mid - 1;
						}
						else
							l = mid + 1;
					}
					if (to != INF&&arr[to].first == nx&&arr[to].second == i + dy) 
						Map[from].push_back({ to,1 });
				}
			}
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < Map[now].size(); i++) {
			int there = Map[now][i].first;
			int there_cost = Map[now][i].second;
			if (dist[there] > cost + there_cost) {
				dist[there] = cost + there_cost;
				pq.push({ -(cost + there_cost),there });
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= N; i++) {
		if (arr[i].second == T)
			ans = min(ans, dist[i]);
	}
	if (ans == INF) {
		printf("-1\n");
	}
	else
		printf("%d\n", ans);
	return 0;
}