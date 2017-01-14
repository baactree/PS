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
int N, M, K, T;
pii arr[1000];
int cache[1000][100];
int max_q[1000][1000];
int width;
int solve(int idx, int k) {
	if (idx == T)
		return 1;
	if (k == K)
		return 0;
	int &ret = cache[idx][k];
	if (ret != -1)
		return ret;
	ret = 0;
	int le, ri, mid;
	int t=T;
	le = idx;
	ri = T - 1;
	while (ri >= le) {
		mid = (le + ri) / 2;
		if (arr[mid].first<=arr[idx].first+width-1) {
			t = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	if (t!=T&&max_q[idx][t] <= width)
		ret |= solve(t + 1, k + 1);
	return ret;
}
extern inline bool possi(int num) {
	memset(cache, -1, sizeof(cache));
	width = num;
	return solve(0, 0);
}
int main() {
	scanf("%d%d%d%d", &N, &M, &K, &T);
	for (int i = 0; i < T; i++)
		scanf("%d%d", &arr[i].second, &arr[i].first);
	sort(arr, arr + T);
	for (int i = 0; i < T; i++) {
		max_q[i][i] = arr[i].second;
		for (int j = i + 1; j < T; j++) {
			max_q[i][j] = max(max_q[i][j - 1], arr[j].second);
		}
	}
	int le, ri, mid;
	int ans;
	le = 1;
	ri = 1000000;
	while (ri >= le) {
		mid = (le + ri) / 2;
		if (possi(mid)) {
			ans = mid;
			ri = mid - 1;
		}
		else
			le = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}