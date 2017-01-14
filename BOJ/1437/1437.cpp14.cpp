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
const int mod = 10007;
int main() {
	scanf("%d", &N);
	if (N == 0)
		printf("0\n");
	else {
		int ans = 1;
		if (N % 3 == 0) {
			while (N) {
				ans *= 3;
				ans %= mod;
				N -= 3;
			}
		}
		else if (N % 3 == 2) {
			while (N != 2) {
				ans *= 3;
				ans %= mod;
				N -= 3;
			}
			ans *= 2;
			ans %= mod;
		}
		else if (N % 3 == 1) {
			while (N > 4) {
				ans *= 3;
				ans %= mod;
				N -= 3;
			}
			ans *= N;
			ans %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}