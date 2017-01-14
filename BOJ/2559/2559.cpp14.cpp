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
int N, K;
int arr[100000];
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int ans = -INF;
	int sum = 0;
	for (int i = 0; i < K; i++)
		sum += arr[i];
	ans = sum;
	for (int i = K; i < N; i++) {
		sum += arr[i];
		sum -= arr[i - K];
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}