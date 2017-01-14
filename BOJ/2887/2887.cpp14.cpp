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
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
pii point[3][100000];
int par[100000];
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	par[find(y)] = find(x);
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &point[j][i].first);
			point[j][i].second = i;
		}
	}
	sort(point[0], point[0] + N);
	sort(point[1], point[1] + N);
	sort(point[2], point[2] + N);
	vector<pair<int, pair<int, int> > > edge;
	for (int i = 0; i < N - 1;i++) {
		for (int j = 0; j < 3; j++) {
			int cost = abs(point[j][i].first - point[j][i + 1].first);
			edge.push_back({ cost,{point[j][i].second,point[j][i + 1].second} });
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < N; i++)
		par[i] = i;
	ll ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		if (find(u) == find(v))
			continue;
		merge(u, v);
		ans += cost;
	}
	printf("%lld\n", ans);
	return 0;
}