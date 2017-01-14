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
string A, B;
int cache[1001][1001];
int solve(int a, int b) {
	if (a == A.size() || b == B.size())
		return 0;
	int &ret = cache[a][b];
	if (ret != -1)
		return ret;
	ret = solve(a + 1, b);
	ret = max(ret, solve(a, b + 1));
	if (A[a] == B[b])
		ret = max(ret, solve(a + 1, b + 1) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> A >> B;
	printf("%d\n", solve(0, 0));
	return 0;
}