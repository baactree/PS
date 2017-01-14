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
string out[7] = { "","Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh" };
string tt[7] = { "","Yakk","Doh","Seh","Ghar","Bang","Sheesh" };
int main() {
	int Case;
	cin >> Case;
	for (int tc = 1; tc <= Case; tc++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b)
			swap(a, b);
		printf("Case %d: ", tc);
		if (a == b) {
			cout << out[a] << endl;
			continue;
		}
		if (a == 6 && b == 5) {
			printf("Sheesh Beesh\n");
			continue;
		}
		cout << tt[a] << " " << tt[b] << endl;
	}
	return 0;
}