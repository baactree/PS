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
		double n;
		cin >> n;
		string str;
		getline(cin, str);
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ')
				continue;
			if (str[i] == '@')
				n *= 3;
			else if (str[i] == '%')
				n += 5;
			else if (str[i] == '#')
				n -= 7;
		}
		printf("%.2lf\n", n);
	}
	return 0;
}