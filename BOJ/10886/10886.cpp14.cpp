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
int cnt[2];
int main() {
	int n;
	int in;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		cnt[in]++;
	}
	if (cnt[0] < cnt[1])
		cout << "Junhee is cute!\n";
	else
		cout << "Junhee is not cute!\n";
	return 0;
}