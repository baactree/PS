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
pii arr[1001]; 
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++) {
			int a, b, p, q;
			scanf("%d%d%d%d", &a, &b, &p, &q);
			arr[a].first += p;
			arr[b].second += p;
			arr[a].second += q;
			arr[b].first += q;
		}
		ll min_value = LINF;
		ll max_value = -LINF;
		for (int i = 1; i <= N; i++) {
			ll temp;
			if (arr[i].first == 0) {
				temp = 0;
			}
			else {
				temp = (1000*(double)arr[i].first*arr[i].first / ((double)arr[i].first*arr[i].first + arr[i].second*arr[i].second));
			}
			min_value = min(min_value, temp);
			max_value = max(max_value, temp);
		}
		printf("%lld\n%lld\n", max_value, min_value);
	}
	return 0;
}