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
	int Case;
	cin >> Case;
	while (Case--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ll dist = y - x;
		ll k = 1;
		ll sum = 0;
		int ans = 0;
		while (true) {
			if (dist >= sum + k * 2) {
				sum += k * 2;
				k++;
				ans += 2;
			}
			else {
				break;
			}
		}
		dist -= sum;
		if (dist != 0) {
			if (dist > k) {
				ans += dist / k;
				ans++;
			}
			else {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}