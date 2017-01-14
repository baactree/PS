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
pii arr[100000];
int N, L;
int main() {
	scanf("%d%d", &N, &L);
	for (int i = L; i <= 100; i++) {
		if (i & 1) {
			int k = i / 2;
			if ((2 * N) % (2 * k + 1) == 0) {
				int t = (2 * N) / (2 * k + 1);
				if (t % 2 == 0) {
					deque<int> ans;
					t /= 2;
					ans.push_back(t);
					for (int j = 1; j <= k; j++) {
						ans.push_front(t - j);
						ans.push_back(t + j);
						if (t - j < 0)
							goto tag;
					}
					for (int j = 0; j < ans.size(); j++)
						printf("%d ", ans[j]);
					printf("\n");
					return 0;
				}
			}
		}
		else {
			int k = i / 2;
			if (N%k == 0) {
				int t = N / k;
				if (t & 1) {
					t /= 2;
					deque<int> dq;
					for (int j = 0; j < k; j++) {
						dq.push_front(t-j);
						dq.push_back(t + 1 + j);
						if (t - j < 0)
							goto tag;
					}
					for (int j = 0; j < dq.size(); j++)
						printf("%d ", dq[j]);
					printf("\n");
					return 0;
				}
			}
		}
	tag:
		continue;
	}
	printf("-1\n");
	return 0;
}