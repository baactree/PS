#include "bits/stdc++.h"
using namespace std;
map<string, int> h;
int node(string s) {
	if (h.count(s) > 0)
		return h[s];
	int cnt = h.size();
	return h[s] = cnt + 1;
}
int capacity[1000][1000];
int source, sink;
bool trip[1000];
int par[1000];
int n;
int bfs() {
	queue<int> q;
	q.push(source);
	par[source] = -1;
	trip[source] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (capacity[now][i] && !trip[i]) {
				q.push(i);
				par[i] = now;
				trip[i] = true;
			}
		}
	}
	if (!trip[sink])
		return 0;
	int c = 0x7fffffff;
	int x = sink;
	while (par[x] != -1) {
		c = min(c, capacity[par[x]][x]);
		x = par[x];
	}
	x = sink;
	while (par[x] != -1) {
		capacity[par[x]][x] -= c;
		capacity[x][par[x]] += c;
		x = par[x];
	}
	return c;
}

int flow() {
	n = h.size();
	int ret = 0;
	while (true) {
		memset(trip, 0, sizeof(trip));
		int f = bfs();
		if (f == 0)break;
		ret += f;
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a, b;
		int f;
		cin >> a >> b >> f;
		int u = node(a);
		int v = node(b);
		capacity[u][v] += f;
		capacity[v][u] += f;
	}
	source = node("A");
	sink = node("Z");
	printf("%d\n", flow());
	return 0;
}