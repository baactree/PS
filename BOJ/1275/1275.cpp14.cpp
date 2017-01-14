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
ll tree[100001];
int arr[100001];
int N, Q;
void update(int idx, int num) {
	while (idx <= N) {
		tree[idx] += num;
		idx += (idx&-idx);
	}
}
ll query(int idx) {
	ll ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= (idx&-idx);
	}
	return ret;
}
int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		update(i, arr[i]);
	}
	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if (x > y)
			swap(x, y);
		printf("%lld\n", query(y) - query(x - 1));
		update(a,-arr[a]);
		update(a, b);
		arr[a] = b;
	}
}