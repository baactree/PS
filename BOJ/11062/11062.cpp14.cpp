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
int arr[1000];
int N;
int cache[1000][1000][2];
int solve(int le, int ri, int mode) {
	if (le == ri)
		return mode ? 0 : arr[le];
	int &ret = cache[le][ri][mode];
	if (ret != -1)
		return ret;
	if (mode) {
		ret = INF;
		ret = min(ret, solve(le + 1, ri, 0));
		ret = min(ret, solve(le, ri - 1, 0));
		return ret;
	}
	ret = max(ret, solve(le + 1, ri, 1) + arr[le]);
	ret = max(ret, solve(le, ri - 1, 1) + arr[ri]);
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		printf("%d\n", solve(0, N - 1, 0));
	}
	return 0;
}