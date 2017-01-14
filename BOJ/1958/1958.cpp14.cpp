/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
string a, b, c;
int la, lb, lc;
int cache[100][100][100];
int search(int ia, int ib, int ic) {
	if (ia == la || ib == lb || ic == lc)
		return 0;
	int &ret = cache[ia][ib][ic];
	if (ret != -1)
		return ret;
	if (a[ia] == b[ib] && b[ib] == c[ic])
		ret = search(ia + 1, ib + 1, ic + 1) + 1;
	ret = max(ret,search(ia + 1, ib, ic));
	ret = max(ret, search(ia, ib + 1, ic));
	ret = max(ret, search(ia, ib, ic + 1));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> a >> b >> c;
	la = a.length();
	lb = b.length();
	lc = c.length();
	printf("%d\n", search(0, 0, 0));
	return 0;
}