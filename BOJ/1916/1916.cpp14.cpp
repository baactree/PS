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
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	Edge edge(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,d });
	}
	int st, fi;
	scanf("%d%d", &st, &fi);
	vector<int> dist(N + 1, INF);
	vector<bool> chk(N + 1, 0);
	Pq pq;
	pq.push({ 0,st });
	dist[st] = 0;
	for (int i = 0; i<N; i++) {
		int now, cost;
		while (!pq.empty()) {
			now = pq.top().second;
			cost = -pq.top().first;
			pq.pop();
			if (!chk[now]) break;
		}
		chk[now] = true;
		for (int j = 0; j<edge[now].size(); j++) {
			int there = edge[now][j].first;
			int there_cost = edge[now][j].second+cost;
			if (chk[there]) continue;
			if (dist[there] > there_cost) {
				dist[there] = there_cost;
				pq.push({ -there_cost,there });
			}
		}
	}
	printf("%d\n", dist[fi]);
	return 0;
}
