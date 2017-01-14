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
Edge edge;
vector<int> arr;
int N, M;
int A, B, K, G;
vector<int> dist;
int gdist[1001][1001];
int mat[1001][1001];
int add(int here, int there, int t) {
	//here에서 there로 갈 때 t시간에 출발하면 몇분 대기해야하는지
	int st = gdist[here][there] - mat[here][there];
	int fi = gdist[here][there];
	t += K;
	if (t<st || t>fi)
		return 0;
	return fi - t;
}
int main() {
	scanf("%d%d%d%d%d%d", &N, &M, &A, &B, &K, &G);
	edge.resize(N + 1);
	arr.resize(G);
	dist.resize(N + 1);
	fill(dist.begin(), dist.end(), INF);
	for (int i = 0; i < G; i++)
		scanf("%d", &arr[i]);
	int a, b, d;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,d });
		edge[b].push_back({ a,d });
		mat[a][b] = d;
		mat[b][a] = d;
	}
	int sum = 0;
	for (int i = 1; i < G; i++) {
		int start = arr[i - 1];
		int finish = arr[i];
		sum += mat[start][finish];
		gdist[start][finish] = sum;
		gdist[finish][start] = sum;
	}
	Pq pq;
	pq.push({ 0,A });
	dist[A] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[now] < cost)
			continue;
		for (auto i : edge[now]) {
			int there = i.first;
			int there_cost = cost + i.second + add(now, there, cost);
			if (dist[there] > there_cost) {
				dist[there] = there_cost;
				pq.push({ -there_cost,there });
			}
		}
	}
	printf("%d\n", dist[B]);
	return 0;
}