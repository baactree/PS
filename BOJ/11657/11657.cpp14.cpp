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
vector<int> dist;
vector<int> cnt;
int main() {
	scanf("%d%d", &N, &M);
	adj.resize(N + 1);
	dist = vector<int>(N + 1, INF);
	cnt = vector<int>(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({ b,d });
	}
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int there = adj[now][i].first;
			int cost = adj[now][i].second;
			if (dist[there] > dist[now] + cost) {
				dist[there] = dist[now] + cost;
				cnt[there]++;
				if (cnt[there] >= N) {
					printf("-1\n");
					return 0;
				}
				q.push(there);
			}
		}
	}
	for (int i = 2; i <= N; i++)
		printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	return 0;
}