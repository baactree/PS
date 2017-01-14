#include "bits/stdc++.h"
using namespace std;
int N, M;
vector<int> Map[100001];
bool trip[100001];
int depth[100001];
int par[100001][17];
void dfs(int v) {
	trip[v] = true;
	for (int i = 0; i < Map[v].size(); i++) {
		int there = Map[v][i];
		if (!trip[there]) {
			depth[there] = depth[v] + 1;
			par[there][0] = v;
			for (int i = 1; i < 17; i++)
				par[there][i] = par[par[there][i - 1]][i - 1];
			dfs(there);
		}
	}
}
int lca(int x, int y) {
	if (depth[x] < depth[y])
		swap(x, y);
	for (int i = 16; i >= 0; i--) 
		if (1 << i <= depth[x] - depth[y])
			x = par[x][i];
	if (x == y)
		return x;
	for (int i = 16; i >= 0;i--)
		if (par[x][i] != par[y][i]) {
			x = par[x][i]; y = par[y][i];
		}
	return par[x][0];
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	dfs(1);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}