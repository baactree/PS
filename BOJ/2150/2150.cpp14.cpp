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
int discoverd[10001];
int scc[10001];
stack<int> st;
int scc_num = 0, vertex_num = 0;
vector<int> edge[10001];
int V, E;
int dfs(int here) {
	int ret = discoverd[here] = vertex_num++;
	st.push(here);
	for (int i = 0; i < edge[here].size(); i++) {
		int there = edge[here][i];
		if (discoverd[there] == -1)
			ret = min(ret, dfs(there));
		else if (scc[there] == -1)
			ret = min(ret, discoverd[there]);
	}
	if (discoverd[here] == ret) {
		while (true) {
			int t = st.top();
			st.pop();
			scc[t] = scc_num;
			if (t == here)
				break;
		}
		scc_num++;
	}
	return ret;
}
int main() {
	memset(discoverd, -1, sizeof(discoverd));
	memset(scc, -1, sizeof(scc));
	scanf("%d%d", &V, &E);
	int a, b;
	for (int i = 0; i < E; i++) {
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
	}
	for (int i = 1; i <= V; i++)
		if (discoverd[i] == -1)
			dfs(i);
	vector<int> ans[10000];
	for (int i = 1; i <= V; i++)
		if (scc[i] != -1)
			ans[scc[i]].push_back(i);
	for (int i = 0; i < scc_num; i++)
		sort(ans[i].begin(), ans[i].end());
	sort(ans, ans + scc_num);
	printf("%d\n", scc_num);
	for (int i = 0; i < scc_num; i++) {
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		printf("-1\n");
	}
	return 0;
}