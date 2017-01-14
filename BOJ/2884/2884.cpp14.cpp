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
	int H, M;
	cin >> H >> M;
	if (M < 45) {
		if (H == 0) {
			H = 23;
			M += 15;
		}
		else {
			H--;
			M += 15;
		}
	}
	else
		M -= 45;
	cout << H << " " << M << endl;
	return 0;
}