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
	int tc;
	scanf("%d", &tc);
	for (int q = 0; q < tc; q++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		printf("$%.2lf\n", a*350.34 + b*230.90 + c*190.55 + d*125.30 + e*180.90);
	}
	return 0;
}