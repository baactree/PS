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
vector<int> adj[1001];
int matched[1001];
bool trip[1001];
bool dfs(int v) {
	if (trip[v])
		return false;
	trip[v] = true;
	for (auto there : adj[v]) {
		if (matched[there] == -1 || dfs(matched[there])) {
			matched[there] = v;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int in;
			scanf("%d", &in);
			adj[i].push_back(in);
		}
	}
	int ans = 0;
	memset(matched, -1, sizeof(matched));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			memset(trip, 0, sizeof(trip));
			if (dfs(i))
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}