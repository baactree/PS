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
int N, M, K;
int matched[1001];
vector<int> edge[1001];
bool trip[1001];
bool dfs(int now) {
	if (trip[now])
		return false;
	trip[now] = true;
	for (int i = 0; i < edge[now].size(); i++) {
		int there = edge[now][i];
		if (matched[there] == -1 || dfs(matched[there])) {
			matched[there] = now;
			return true;
		}
	}
	return false;
}
int main() {
	memset(matched, -1, sizeof(matched));
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int in;
			scanf("%d", &in);
			edge[i].push_back(in);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(trip, 0, sizeof(trip));
		if (dfs(i))
			ans++;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		memset(trip, 0, sizeof(trip));
		if (dfs(i)) {
			ans++;
			cnt++;
		}
		if (cnt == K)
			break;
	}
	printf("%d\n",ans);
	return 0;
}