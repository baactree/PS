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
int arr[10000];
int main() {
	int Case;
	scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		deque<int> dq;
		for (int i = N-1; i >=0; i--) {
			if (i & 1) {
				dq.push_back(arr[i]);
			}
			else {
				dq.push_front(arr[i]);
			}
		}
		dq.push_back(dq[0]);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans = max(ans, abs(dq[i] - dq[i + 1]));
		}
		printf("%d\n", ans);
	}
	return 0;
}