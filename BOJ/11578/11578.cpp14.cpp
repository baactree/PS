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
int mat[100];
int cache[1 << 10][100];
int solve(int idx, int state) {
	if (idx == M) {
		if (state == (1 << N) - 1)
			return 0;
		return INF;
	}
	int &ret = cache[state][idx];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, state);
	ret = min(ret, solve(idx + 1, state | mat[idx]) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int cnt;
		scanf("%d", &cnt);
		int state = 0;
		for (int j = 0; j < cnt; j++) {
			int now;
			scanf("%d", &now);
			state |= (1 << (now - 1));
		}
		mat[i] = state;
	}
	int ans = solve(0, 0);
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}