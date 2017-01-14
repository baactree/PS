#include "bits/stdc++.h"
using namespace std;
int par[10001];
int child[10001][2];
int dist[10001][2];
int N;
int cnt;
void search(int v, int d) {
	if (child[v][0] != -1)
		search(child[v][0], d + 1);
	cnt++;
    dist[d][0] = min(dist[d][0], cnt);
    dist[d][1] = max(dist[d][1], cnt);
	if (child[v][1] != -1)
		search(child[v][1], d + 1);
}
int main() {
	cin >> N;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		child[a][0] = b;
		child[a][1] = c;
		par[b] = par[c] = a;
	}
	for (int i = 1; i <= N; i++)
		dist[i][0] = N;
	int root;
	for (int i = 1; i <= N; i++)
		if (par[i] == 0)
			root = i;
	search(root, 1);
	int ans = -1;
	int ans_idx;
	for (int i = 1; i <= N; i++) {
		int sub = dist[i][1] - dist[i][0] + 1;
		if (ans < sub) {
			ans = sub;
			ans_idx = i;
		}
	}
	printf("%d %d\n", ans_idx, ans);
	return 0;
}