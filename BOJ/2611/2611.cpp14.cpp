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
Edge edge;
int par[1001];
int dist[1001];
int main() {
	scanf("%d%d", &N, &M);
	edge.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,-d });
	}
	Pq pq;
	pq.push({ 0,1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (now == 1 && cost != 0)
			continue;
		if (dist[now] < cost)
			continue;
		for (int i = 0; i < edge[now].size(); i++) {
			int there = edge[now][i].first;
			int there_cost = edge[now][i].second + cost;
			if (dist[there] > there_cost) {
				dist[there] = there_cost;
				par[there] = now;
				pq.push({ -there_cost,there });
			}
		}
	}
	printf("%d\n", -dist[1]);
	stack<int> st;
	int now = 1;
	while (true) {
		st.push(now);
		now = par[now];
		if (now == 1) {
			st.push(1);
			break;
		}
	}
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}