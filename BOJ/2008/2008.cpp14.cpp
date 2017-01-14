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
int N, M, X, Y;
int st, fi;
int cache[101][501];
int arr[500];
int solve(int now, int idx) {
	if (now<1 || now>N)
		return INF;
	if (now == fi&&idx == M) {
		return 0;
	}
	int &ret = cache[now][idx];
	if (ret != -1)
		return ret;
	ret = INF;
	ret = min(ret, solve(now + 1, idx) + Y);
	ret = min(ret, solve(now - 1, idx) + Y);
	if (idx != M) {
		if (arr[idx] == now) {
			ret = min(ret, solve(now, idx + 1) + X);
			ret = min(ret, solve(now + 1, idx + 1));
		}
		else if (arr[idx] + 1 == now) {
			ret = min(ret, solve(now, idx + 1) + X);
			ret = min(ret, solve(now - 1, idx + 1));
		}
		else
			ret = min(ret, solve(now, idx + 1));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	scanf("%d%d%d%d", &st, &fi, &X, &Y);
	for (int i = 0; i < M; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", solve(st, 0));
	return 0;
}