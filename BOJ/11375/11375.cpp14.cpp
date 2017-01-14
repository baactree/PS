#include "bits/stdc++.h"
using namespace std;
class MF {
public:
	int n;
	int source, sink;
	vector<vector<int> > Map;
	vector<bool> trip;
	vector<int> par;
	MF(int n) :n(n) {
		Map.resize(n);
		trip.resize(n);
		par.resize(n, -1);
	}
	void add_adge(int u, int v) {
		Map[u].push_back(v);
	}
	bool dfs(int x) {
		if (x == -1)
			return true;
		for (int i = 0; i < Map[x].size(); i++) {
			int there = Map[x][i];
			if (!trip[there]) {
				trip[there] = true;
				if (dfs(par[there])) {
					par[there] = x;
					return true;
				}
			}
		}
		return false;
	}
	int flow() {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			fill(trip.begin(), trip.end(), 0);
			if (dfs(i)) {
				ans += 1;
			}
		}
		return ans;
	}
};
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	MF mf(max(N, M));
	for (int i = 0; i < N; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int in;
			scanf("%d", &in);
			mf.add_adge(i, in - 1);
		}
	}
	printf("%d\n", mf.flow());
	return 0;
}