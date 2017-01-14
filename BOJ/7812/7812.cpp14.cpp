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
int N;
Edge edge;
ll ans;
ll sum;
int cnt[10000];
int dfs1(int now, int par, ll dep) {
	sum += dep;
	int ret = 1;
	for (int i = 0; i < edge[now].size(); i++) {
		int there = edge[now][i].first;
		int cost = edge[now][i].second;
		if (there != par)
			ret+=dfs1(there, now, dep + cost);
	}
	cnt[now] = ret;
	return ret;
}
void dfs2(int now, int par, ll sum) {
	ans = min(ans, sum);
	for (int i = 0; i < edge[now].size(); i++) {
		int there = edge[now][i].first;
		int cost = edge[now][i].second;
		if (there != par)
			dfs2(there, now, sum - cnt[there] * cost + (N - cnt[there])*cost);
	}
}
int main() {
	while (true) {
		scanf("%d", &N);
		if (N == 0)
			break;
		edge.clear();
		edge.resize(N);
		for (int i = 0; i < N - 1; i++) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			edge[a].push_back({ b,w });
			edge[b].push_back({ a,w });
		}
		sum = 0;
		dfs1(0, 0, 0);
		ans = LINF;
		dfs2(0, 0, sum);
		printf("%lld\n", ans);
	}
}