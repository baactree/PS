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
ll cache[101][101];
vector<pii> edge[101][101];
extern inline bool possi(int sx,int sy,int x, int y) {
	if (x<0 || x>N || y<0 || y>M)
		return false;
	for (int i = 0; i < edge[sx][sy].size(); i++)
		if (edge[sx][sy][i] == make_pair(x, y))
			return false;
	return true;
}
ll search(int x, int y) {
	if (x == N&&y == M)
		return 1;
	ll &ret = cache[x][y];
	if (ret != -1)
		return ret;
	ret = 0;
	if (possi(x,y,x + 1, y))
		ret += search(x + 1, y);
	if (possi(x,y,x, y + 1))
		ret += search(x, y + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		edge[b][a].push_back({ d,c });
		edge[d][c].push_back({ b,a });
	}
	printf("%lld\n", search(0, 0));
	return 0;
}