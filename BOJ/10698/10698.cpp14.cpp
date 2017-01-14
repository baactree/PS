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
	for (int tc = 1; tc <= Case; tc++) {
		int a, b, c;
		string op,g;
		cin >> a >> op >> b >> g >> c;
		printf("Case %d: ", tc);
		if (op == "+") {
			printf("%s\n", a + b == c ? "YES" : "NO");
		}
		else {
			printf("%s\n", a - b == c ? "YES" : "NO");
		}
	}
	return 0;
}