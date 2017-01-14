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
vector<pair<int, int> > edge[1001];
int dist[1001][1001];
int N, M, X;
void dijk(int st) {
	dist[st][st] = 0;
	priority_queue<pair<int, int> >pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[st][now] < cost)
			continue;
		for (int i = 0; i < edge[now].size(); i++) {
			int there = edge[now][i].first;
			int there_cost = edge[now][i].second + cost;
			if (dist[st][there]>there_cost) {
				dist[st][there] = there_cost;
				pq.push({ -there_cost,there });
			}
		}
	}
}
int main() {
	memset(dist, 0x3f, sizeof(dist));
	scanf("%d%d%d", &N, &M, &X);
	int a, b, d;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,d });
	}
	for (int i = 1; i <= N; i++) 
		dijk(i);
	int ans = 0;
	for (int i = 1; i <= N; i++) 
		ans = max(ans, dist[i][X] + dist[X][i]);
	printf("%d\n",ans);
	return 0;
}