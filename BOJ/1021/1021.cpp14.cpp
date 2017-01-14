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
int arr[100];
int main() {
	scanf("%d%d", &N, &K);
	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	int ans = 0;
	for (int i = 0; i < K; i++) {
		int in;
		scanf("%d", &in);
		int idx = find(dq.begin(), dq.end(), in) - dq.begin();
		int le = idx;
		int ri = dq.size() - idx;
		if (le < ri) {
			while (le--) {
				dq.push_back(dq.front());
				dq.pop_front();
                ans++;
			}
		}
		else {
			while (ri--) {
				dq.push_front(dq.back());
				dq.pop_back();
                ans++;
			}
		}
		dq.pop_front();
	}
	printf("%d\n", ans);
	return 0;
}
