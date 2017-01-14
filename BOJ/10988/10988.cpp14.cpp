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
int a, b;
int main() {
	string str;
	int len;
	cin >> str;
	len = str.length();
	int le, ri;
	le = 0; ri = len - 1;
	while (le < ri&&str[le] == str[ri])
		le++, ri--;
	printf("%d\n", le >= ri);
	return 0;
}