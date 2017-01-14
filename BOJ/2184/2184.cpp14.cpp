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
int N, L;
vector<int> arr;
ll cache[1001][1001][2];
int idx;
ll solve(int left, int right, bool lr) {
	if (left == 0 && right == N)
		return 0;
	ll &ret = cache[left][right][lr];
	if (ret != -1)
		return ret;
	ret = 2 * 1e9;
	if (left != 0) {
		ll dist = abs(lr ? arr[right] - arr[left - 1] : arr[left] - arr[left - 1]);
		int cnt = left - 0 + N - right;
		ret = min(ret, solve(left - 1, right, 0) + cnt*dist);
	}
	if (right != N) {
		ll dist = abs(lr ? arr[right] - arr[right + 1] : arr[left] - arr[right + 1]);
		int cnt = left - 0 + N - right;
		ret = min(ret, solve(left, right + 1, 1) + cnt*dist);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	scanf("%d", &L);
	arr.resize(N + 1);
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);
	arr[N] = L;
	sort(all(arr));
	idx = find(all(arr),L) - arr.begin();
	printf("%lld\n", solve(idx, idx, 0));
	return 0;
}