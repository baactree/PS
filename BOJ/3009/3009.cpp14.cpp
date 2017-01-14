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
	pair<int, int> p[3];
	for (int i = 0; i < 3; i++) {
		cin >> p[i].first >> p[i].second;
	}
	pair<int, int> ans = p[0];
	for (int i = 1; i < 3; i++)
		ans.first ^= p[i].first, ans.second ^= p[i].second;
	cout << ans.first << " "<<ans.second << endl;
	return 0;
}