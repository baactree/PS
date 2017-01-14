/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////

int main() {
	string str;
	cin >> str;
	int len = str.length();
	int idx = len / 2;
	int ans=INF;
	for (int i = idx; i < len; i++) {
		int le, ri;
		le = ri = i;
		while (le >= 0 && ri < len && str[le] == str[ri]) {
			le--;
			ri++;
		}
		if (ri == len) {
			ans = min(ans, len + le + 1);
		}
		le = i - 1;
		ri = i;
		while (le >= 0 && ri < len && str[le] == str[ri]) {
			le--;
			ri++;
		}
		if (ri == len) {
			ans = min(ans, len + le + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}