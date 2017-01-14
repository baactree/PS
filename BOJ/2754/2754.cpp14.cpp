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
	double ans = 0;
	ans = 'A' + 4 - str[0];
	if (str[1] == '+')
		ans += 0.3;
	else if (str[1] == '-')
		ans -= 0.3;
	if (str[0] == 'F')
		ans = 0;
	printf("%.1lf\n", ans);
	return 0;
}