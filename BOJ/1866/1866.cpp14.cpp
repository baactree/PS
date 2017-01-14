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
int N, T, H;
int arr[3001];
int cache[3001][3001][2];
int solve(int idx,int loc,int pre) {
	if (idx == N + 1)
		return 0;
	int &ret = cache[idx][loc][pre];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, loc, 0) + abs(arr[loc] - arr[idx])*T;
	if (pre) {
		ret = min(ret, solve(idx + 1, loc, 0) + abs(arr[loc] - arr[idx])*T);
		if(loc!=N+1)
			ret = min(ret, solve(idx, loc + 1, 1));
		return ret;
	}
	ret = min(ret, solve(idx + 1, loc, 0) + abs(arr[loc] - arr[idx])*T);
	if(loc!=N+1)
		ret = min(ret, solve(idx, loc + 1, 1) + H);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	scanf("%d%d", &T, &H);
	sort(arr, arr + N +  1);
	printf("%d\n", solve(0, 0, 0));
	return 0;
}