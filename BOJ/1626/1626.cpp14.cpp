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
int par[50001];
vector<pair<int, ll>> edge[50001];
vector<pair<ll, pair<int, int> > > krus;
vector<pair<int, ll> >tree[50001];
int depth[50001];
ll dp[50001][17][2];
int parent[50001][17];
bool used[200000];
const bool comp(const ll &a, const ll &b) {
	return a > b;
}
void dfs(int now, int par, int d) {
	depth[now] = d;
	for (int i = 0; i < tree[now].size(); i++) {
		int there = tree[now][i].first;
		ll weight = tree[now][i].second;
		if (there == par)
			continue;
		dp[there][0][0] = weight;
		dp[there][0][1] = -1;
		parent[there][0] = now;
		for (int i = 1; i < 17; i++) {
			parent[there][i] = parent[parent[there][i - 1]][i - 1];
			vector<ll> temp;
			temp.push_back(dp[there][i - 1][0]);
			temp.push_back(dp[there][i - 1][1]);
			temp.push_back(dp[parent[there][i - 1]][i - 1][0]);
			temp.push_back(dp[parent[there][i - 1]][i - 1][1]);
			sort(temp.begin(), temp.end(), comp);
			temp.erase(unique(temp.begin(), temp.end()), temp.end());
			dp[there][i][0] = temp[0];
			if (temp.size() > 1)
				dp[there][i][1] = temp[1];
			else
				dp[there][i][1] = -1;
		}
		dfs(there, now, d + 1);
	}
}
ll lca(int x, int y,int w) {
	if (depth[x] < depth[y])
		swap(x, y);
	ll ret = -1;
	for (int i = 16; i >= 0; i--) {
		if ((1 << i) <= depth[x] - depth[y]) {
			if (dp[x][i][0] != w) {
				ret = max(ret, dp[x][i][0]);
			}
			else if (dp[x][i][1] != -1) {
				ret = max(ret, dp[x][i][1]);
			}
			x = parent[x][i];
		}
	}
	if (x == y)
		return ret==-1?w:ret;
	for (int i = 16; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			if (dp[x][i][0] != w) {
				ret = max(ret, dp[x][i][0]);
			}
			else if (dp[x][i][1] != -1) {
				ret = max(ret, dp[x][i][1]);
			}
			if (dp[y][i][0] != w) {
				ret = max(ret, dp[y][i][0]);
			}
			else if (dp[y][i][1] != -1) {
				ret = max(ret, dp[y][i][1]);
			}
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	ret = max(ret, max(dp[x][0][0]==w?dp[x][0][1]:dp[x][0][0], dp[y][0][0]==w?dp[y][0][1]:dp[y][0][0]));
	return ret==-1?w:ret;
}
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	par[find(x)] = find(y);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		par[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		ll d;
		scanf("%d%d%lld", &a, &b, &d);
		edge[a].push_back({ b,d });
		edge[b].push_back({ a,d });
		krus.push_back({ d,{ a,b } });
	}
	sort(krus.begin(), krus.end());
	ll ans = 0;
	int root;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int u = krus[i].second.first;
		int v = krus[i].second.second;
		ll w = krus[i].first;
		if (find(u) != find(v)) {
			used[i] = true;
			ans += w;
			cnt++;
			merge(u, v);
			tree[u].push_back({ v,w });
			tree[v].push_back({ u,w });
			root = u;
		}
	}
    if(cnt!=N-1){
        printf("-1\n");
        return 0;
    }
	dfs(root, 0, 0);
	ll val = LINF;
	for (int i = 0; i < M; i++) {
		if (used[i])
			continue;
		int u = krus[i].second.first;
		int v = krus[i].second.second;
		ll w = krus[i].first;
		ll t = w - lca(u, v, w);
		if (t < 1)
			continue;
		val = min(val, t);
	}
	printf("%lld\n", val == LINF ? -1 : ans + val);
	return 0;
}
