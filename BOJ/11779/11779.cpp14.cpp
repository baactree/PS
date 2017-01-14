#include "bits/stdc++.h"
using namespace std;
class dijk {
public:
	vector<int> dist;
	vector<vector<pair<int, int> > >edge;
	priority_queue<pair<int, int> >pq;
	vector<int> path;
	const int inf = 0x3f3f3f3f;
	dijk(int v) {
		edge.clear();
		edge.resize(v + 1);
	}
	void init(int v) {
		while (!pq.empty())
			pq.pop();
		dist.clear();
		dist.resize(v + 1);
		fill(dist.begin(), dist.end(), inf);
		path.clear();
		path.resize(v + 1);
	}
	void get_dist(int st) {
		dist[st] = 0;
		pq.push({ 0,st });
		while (!pq.empty()) {
			int now = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[now] < cost)
				continue;
			for (int i = 0; i < edge[now].size(); i++) {
				int there = edge[now][i].first;
				int there_cost = edge[now][i].second + cost;
				if (dist[there] > there_cost) {
					dist[there] = there_cost;
					path[there] = now;
					pq.push({ -there_cost,there });
				}
			}
		}
	}
	vector<int> get_path(int st, int fi) {
		vector<int> ret;
		int now = fi;
		while (now) {
			ret.push_back(now);
			now = path[now];
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	dijk solve(n);
	solve.init(n);
	int a, b, d;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		solve.edge[a].push_back({ b,d });
	}
	int st, fi;
	scanf("%d%d", &st, &fi);
	solve.get_dist(st);
	printf("%d\n", solve.dist[fi]);
	vector<int> path = solve.get_path(st, fi);
	printf("%d\n", path.size());
	for (int i = 0; i < path.size(); i++)
		printf("%d ", path[i]);
	return 0;
}