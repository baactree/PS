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
struct Node {
	int x, y, r;
};
Node arr[1000];
int par[1002];
//left,right
pair<int, int> dist[1002];
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	par[y] = x;
	dist[x].first = min(dist[x].first, dist[y].first);
	dist[x].second = min(dist[x].second, dist[y].second);
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int W, N;
		scanf("%d%d", &W, &N);
		for (int i = 0; i < N; i++)
			scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].r);
		vector<pair<double, pair<int, int> > > edge;
		edge.push_back({ (double)W,{N,N + 1} });
		dist[N].first = 0;
		dist[N].second = W;
		dist[N + 1].first = W;
		dist[N + 1].second = 0;
		par[N] = N;
		par[N + 1] = N + 1;
		for (int i = 0; i < N; i++) {
			par[i] = i;
			dist[i].first = max(arr[i].x - arr[i].r, 0);
			dist[i].second = max(W - arr[i].x - arr[i].r, 0);
			edge.push_back({ (double)dist[i].first,{i,N} });
			edge.push_back({ (double)dist[i].second,{i,N + 1} });
			for (int j = i+1; j < N; j++) {
				double dist = max(0.0, hypot(arr[i].x - arr[j].x, arr[i].y - arr[j].y)-arr[i].r-arr[j].r);
				edge.push_back({ dist,{i,j} });
			}
		}
		sort(edge.begin(), edge.end());
		double ans = 1e9;
		int cnt = 0;
		for (int i = 0; i < edge.size(); i++) {
			double cost = edge[i].first;
			int u = edge[i].second.first;
			int v = edge[i].second.second;
			u = find(u);
			v = find(v);
			if (u==v)
				continue;
			if (dist[u].first == 0) {
				if (dist[v].second == 0) {
					ans = min(ans, cost);
				}
			}
			else if (dist[u].second == 0) {
				if (dist[v].first == 0) {
					ans = min(ans, cost);
				}
			}
			cnt++;
			if (cnt == N + 1)
				break;
			merge(u, v);
		}
		if (ans == 0)
			puts("0");
		else
			printf("%.6lf\n", ans / 2);
	}
	return 0;
}