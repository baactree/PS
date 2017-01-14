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
vector<int> edge[10001];
int disc[10001];
bool ans[10001];
int N, M;
int ct = 0;
int dfs(int here, bool root) {
	disc[here] = ct++;
	int child = 0;
	int ret = disc[here];
	for (int i = 0; i < edge[here].size(); i++) {
		int there = edge[here][i];
		if (disc[there] == -1) {
			child++;
			int subtree = dfs(there, 0);
			if (!root&&subtree >= disc[here])
				ans[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, disc[there]);
	}
	if (root&&child >= 2)
		ans[here] = 1;
	return ret;
}
int main() {
	memset(disc, -1, sizeof(disc));
	scanf("%d%d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		if (disc[i] == -1)
			dfs(i, 1);
	int cnt = 0;
	for (int i = 1; i <= N; i++)
		if (ans[i])
			cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i <= N; i++)
		if (ans[i])
			printf("%d ", i);
	printf("\n");
	return 0;
}