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
int main() {
	while (true) {
		int N, P;
		scanf("%d", &N);
		if (N == 0)
			break;
		scanf("%d", &P);
		for (int i = 1; i <= N; i+=2) {
			int a, b, c;
			a = i + 1;
			b = N - i;
			c = b + 1;
			if (P == i || P == a || P == b || P == c) {
				vector<int> ans;
				ans.push_back(i);
				ans.push_back(a);
				ans.push_back(b);
				ans.push_back(c);
				sort(ans.begin(), ans.end());
				for (int j = 0; j < ans.size(); j++) {
					if (ans[j] != P)
						printf("%d ", ans[j]);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}