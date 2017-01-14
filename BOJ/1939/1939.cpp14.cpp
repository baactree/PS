/////////////////////////////////////////////////////
#ifdef _DEBUG
#include "bits_stdc++.h"
#else
#include "bits/stdc++.h"
#endif
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
typedef vector<int>::iterator It;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
#define all(x) x.begin(),x.end()
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int N, M;
Edge adj;
int st, fi;
bool trip[10001];
void dfs(int v, int cost) {
	if (trip[v])
		return;
	trip[v] = true;
	for (auto there : adj[v]) {
		if (there.second >= cost)
			dfs(there.first, cost);
	}
}
bool possi(int num) {
	memset(trip, 0, sizeof(trip));
	dfs(st,num);
	return trip[fi];
}
int main() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({ b,d });
		adj[b].push_back({ a,d });
	}
	scanf("%d%d", &st, &fi);
	int le, ri, mid;
	le = 0; ri = 1e9;
	int ans;
	while (ri >= le) {
		mid = (le + ri) / 2;
		if (possi(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}