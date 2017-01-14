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
int N, M;
int arr[100000];
ll sum;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	ll ans = 0;
	for (int i = 0; i + M <= N; i++) {
		if (i == 0){
			for (int j = 0; j < M; j++)
				sum += arr[j];
		}
		else {
			sum -= arr[i - 1];
			sum += arr[i + M - 1];
		}
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}