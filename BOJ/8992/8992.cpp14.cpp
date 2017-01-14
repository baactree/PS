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
struct MCMF {
	int V, totalFlow, totalCost;
	struct Edge {
		int target, capacity, cost, flow;
		Edge* dual;
		Edge(int target, int capacity, int cost) :
			target(target), capacity(capacity), cost(cost), flow(0) {}
		inline int residual() const {
			if (flow < 0)
				return -flow;
			return capacity - flow;
		}
		inline int getCost()const {
			if (flow < 0)
				return -dual->cost;
			return cost;
		}
		void push(int amt) {
			flow += amt;
			dual->flow -= amt;
		}
	};
	vector<vector<Edge*> > adj;
	MCMF(int n) :V(n), totalFlow(0), totalCost(0), adj(n) {}
	~MCMF() {
		for (int i = 0; i < V; i++)
			for (int j = 0; j < adj[i].size(); j++)
				delete adj[i][j];
	}
	void setEdge(int u, int v, int uvCapacity, int uvCost) {
		Edge* uv = new Edge(v, uvCapacity, uvCost);
		Edge* vu = new Edge(u, 0, 0);
		uv->dual = vu;
		vu->dual = uv;
		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}
	pii improve(int s, int t) {
		while (true) {
			vector<int> dist(V, INF), par(V, -1), edgeNo(V, -1), capa(V, -1);
			par[s] = s;
			dist[s] = 0;
			capa[s] = INF;
			queue<int> q;
			q.push(s);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				for (int i = 0; i < adj[now].size(); i++) {
					Edge* e = adj[now][i];
					if (e->residual() <= 0)
						continue;
					int thereCost = dist[now] + e->getCost();
					if (dist[e->target] > thereCost) {
						dist[e->target] = thereCost;
						q.push(e->target);
						par[e->target] = now;
						edgeNo[e->target] = i;
						capa[e->target] = min(capa[now], e->residual());
					}
				}
			}
			if (dist[t] == INF)
				break;
			int here = t, amt = capa[t];
			while (here != s) {
				int there = par[here];
				adj[there][edgeNo[here]]->push(amt);
				here = there;
			}
			totalFlow += amt;
			totalCost += dist[t] * amt;
		}
		return{ totalFlow,totalCost };
	}
};
struct Node {
	int x1, y1, x2, y2, w;
};
int N, M;
Node n[200];
Node m[200];
int s, t, V;
pii solve() {
	s = 0;
	t = N + M + 1;
	V = t + 1;
	MCMF mcmf(V);
	for (int i = 0; i < N; i++)
		mcmf.setEdge(s, i + 1, 1, 0);
	for (int i = 0; i < M; i++)
		mcmf.setEdge(N + 1 + i, t, 1, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if(n[i].x1<=m[j].x1&&m[j].x1<=n[i].x2)
				if (m[j].y1 <= n[i].y1&&n[i].y1 <= m[j].y2) 
					mcmf.setEdge(i + 1, j + 1 + N, 1, -(n[i].w*m[j].w));
		}
	return mcmf.improve(s, t);
}
int main(){
	int tc;
	cin >> tc;
	while (tc--) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d%d%d", &n[i].x1, &n[i].y1, &n[i].x2, &n[i].y2, &n[i].w);
			if (n[i].x1 > n[i].x2)
				swap(n[i].x1, n[i].x2);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d%d%d", &m[i].x1, &m[i].y1, &m[i].x2, &m[i].y2, &m[i].w);
			if (m[i].y1 > m[i].y2)
				swap(m[i].y1, m[i].y2);
		}
		pii ans = solve();
		printf("%d %d\n", ans.first, -ans.second);
	}
	return 0;
}