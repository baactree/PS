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
		int N;
		cin >> N;
		string max;
		int max_value = 0;
		for (int i = 0; i < N; i++) {
			string in;
			int value;
			cin >> in >> value;
			if (max_value < value) {
				max_value = value;
				max = in;
			}
		}
		cout << max << endl;
	}
	return 0;
}