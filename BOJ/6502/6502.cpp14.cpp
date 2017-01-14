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
int r, w, l;
int main() {
	int cnt = 0;
	while (true) {
		cnt++;
		scanf("%d", &r);
		if (r == 0)
			break;
		scanf("%d%d", &w, &l);
		if (hypot(w, l) <= 2*r)
			printf("Pizza %d fits on the table.\n", cnt);
		else
			printf("Pizza %d does not fit on the table.\n", cnt);
	}
	return 0;
}