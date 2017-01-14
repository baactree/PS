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
int N;
int arr[500];
int cache[501][501];
int sum[500];
int solve(int left,int right) {
	if (left == right)
		return 0;
	int &ret = cache[left][right];
	if (ret != -1)
		return ret;
	ret = 2*1e9;
	for (int i = left; i < right; i++)
		ret = min(ret,solve(left,i)+solve(i+1,right)+sum[i]-sum[left]+arr[left]+sum[right]-sum[i]);
	return ret;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sum[0] = arr[0];
		for (int i = 1; i < N; i++)
			sum[i] = sum[i - 1] + arr[i];
		printf("%d\n", solve(0, N - 1));
	}
	return 0;
}