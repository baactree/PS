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
char input[201];
int cache[201];
int N;
int solve(int idx) {
	if (idx == N)
		return true;
	int &ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = 0;
	if (idx + 1 < N&&input[idx] == '0'&&input[idx + 1] == '1')
		ret |= solve(idx + 2);
	if (idx + 2 < N) {
		if (input[idx] == '1'&&input[idx + 1] == '0'&&input[idx + 2] == '0') {
			int nidx = idx + 2;
			while (nidx<N&&input[nidx] == '0')
				nidx++;
			while (nidx < N&&input[nidx] == '1') {
				nidx++;
				ret |= solve(nidx);
			}
		}
	}
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(cache, -1, sizeof(cache));
		scanf("%s", input);
		N = strlen(input);
		printf("%s\n", solve(0) ? "YES" : "NO");
	}
	return 0;
}