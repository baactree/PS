#include "bits/stdc++.h"
using namespace std;
vector<int> Map[1001];
int N, M;
int V;
bool trip[1001];
void dfs(int v) {
	if (trip[v])
		return;
	trip[v] = true;
	printf("%d ", v);
	for (int i = 0; i < Map[v].size(); i++)
		dfs(Map[v][i]);
}
void bfs(int v) {
	queue<int> q;
	q.push(v);
	trip[v] = true;
	while (!q.empty()) {
		int now = q.front();
		printf("%d ", now);
		q.pop();
		for (int i = 0; i < Map[now].size(); i++) 
			if (!trip[Map[now][i]]) {
				trip[Map[now][i]] = true;
				q.push(Map[now][i]);
			}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &V);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		if (!Map[i].empty())
			sort(Map[i].begin(), Map[i].end());
	dfs(V);
	printf("\n");
	memset(trip, 0, sizeof(trip));
	bfs(V);
	printf("\n");
	return 0;
}