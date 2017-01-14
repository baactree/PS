/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef vector<vector<pair<int, int> > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pair<int, int> > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
vector<int> edge[501];
vector<int> re_edge[501];
bool trip[501];
int N, M;
int dfs(int v) {
	if (trip[v])
		return 0;
	trip[v] = true;
	int ret = 1;
	for (int i = 0; i < edge[v].size(); i++) {
		ret += dfs(edge[v][i]);
	}
	return ret;
}
int dfs2(int v) {
	if (trip[v])
		return 0;
	trip[v] = true;
	int ret = 1;
	for (int i = 0; i < re_edge[v].size(); i++) {
		ret += dfs2(re_edge[v][i]);
	}
	return ret;
}
int main() {
	scanf("%d%d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		re_edge[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(trip, 0, sizeof(trip));
		int sum = dfs(i);
		memset(trip, 0, sizeof(trip));
		sum += dfs2(i);
		if (sum == N + 1)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}