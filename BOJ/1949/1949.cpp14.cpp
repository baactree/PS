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
int N;
int arr[10001];
vector<int> edge[10001];
int cache[10001][2];
int search(int now, int par) {
	for (int i = 0; i < edge[now].size(); i++) {
		if (edge[now][i] == par)
			continue;
		search(edge[now][i], now);
	}
	cache[now][0] = 0;
	cache[now][1] = arr[now];
	for (int i = 0; i < edge[now].size(); i++) {
		if (edge[now][i] == par)
			continue;
		cache[now][0] += max(cache[edge[now][i]][0], cache[edge[now][i]][1]);
		cache[now][1] += cache[edge[now][i]][0];
	}
	return max(cache[now][0], cache[now][1]);
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	edge[0].push_back(1);
	printf("%d\n", search(0, 0));
	return 0;
}