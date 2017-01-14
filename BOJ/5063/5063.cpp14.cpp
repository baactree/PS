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
	int Case;
	cin >> Case;
	while (Case--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b - c > a) {
			cout << "advertise\n";
		}
		else if (b - c < a)
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}
	return 0;
}