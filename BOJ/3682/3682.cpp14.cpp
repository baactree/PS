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
vector<vector<int> > edge;
vector<int> Sccid;
vector<int> discoverd;
stack<int> st;
int scc_num, vertex_num;
int dfs(int here) {
	int ret = discoverd[here] = vertex_num++;
	st.push(here);
	for (auto there : edge[here]) {
		if (discoverd[there] == -1)
			ret = min(ret, dfs(there));
		else if (Sccid[there] == -1)
			ret = min(ret, discoverd[there]);
	}
	if (ret == discoverd[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			Sccid[t] = scc_num;
			if (t == here)
				break;
		}
		scc_num++;
	}
	return ret;
}
int solve() {
	int n = edge.size();
	scc_num = vertex_num = 0;
	Sccid = discoverd = vector<int>(n, -1);
	for (int i = 1; i < n; i++)
		if (discoverd[i] == -1)
			dfs(i);
	if (scc_num == 1)
		return 0;
	vector<int> indegree(scc_num,0);
	vector<int> outdegree(scc_num,0);
	for (int i = 1; i < n;i++)
		for (auto there : edge[i]) {
			if (Sccid[i] != Sccid[there]) {
				outdegree[Sccid[i]]++;
				indegree[Sccid[there]]++;
			}
		}
	int out = 0, in = 0;
	for (int i = 0; i < scc_num; i++) {
		if (!indegree[i]) out++;
		if (!outdegree[i]) in++;
	}
	return max(out, in);
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int N, M;
		scanf("%d%d", &N, &M);
		edge.clear();
		edge.resize(N + 1);
		int a, b;
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
		}
		printf("%d\n",solve());
	}
	return 0;
}