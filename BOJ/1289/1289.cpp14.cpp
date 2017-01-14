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
Edge edge(100001);
ll dp[100001];
ll search(int now, int par) {
	ll ret = 0;
	dp[now] = 1;
	for (int i = 0; i < edge[now].size(); i++) {
		int there = edge[now][i].first;
		int cost = edge[now][i].second;
		if (there == par)
			continue;
		ret = (ret + search(there, now)) % MOD;
		ll temp = (cost*dp[there]) % MOD;
		ret = (ret + (temp*dp[now]) % MOD) % MOD;
		dp[now] = (dp[now] + temp) % MOD;
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	int a, b, d;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &a, &b, &d);
		edge[a].push_back({ b,d });
		edge[b].push_back({ a,d });
	}
	printf("%lld\n", search(1, 0));
	return 0;
}