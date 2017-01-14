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
int N,K;
int cache[100][100][2];
int solve(int idx, int k, int pre) {
	if (idx == N) {
		if(k==K)
			return 1;
		return 0;
	}
	int &ret = cache[idx][k][pre];
	if (ret != -1)
		return ret;
	ret = 0;
	if (pre) {
		ret += solve(idx + 1, k + 1, 1);
		ret += solve(idx + 1, k, 0);
		return ret;
	}
	ret += solve(idx + 1, k, 1);
	ret += solve(idx + 1, k, 0);
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &N,&K);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}