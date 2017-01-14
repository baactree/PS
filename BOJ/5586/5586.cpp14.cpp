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
	string str;
	cin >> str;
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;
	for (int i = 2; i < str.size(); i++) {
		string temp(str.begin() + i - 2, str.begin() + i + 1);
		if (temp == "JOI")
			cnt1++;
		if (temp == "IOI")
			cnt2++;
	}
	printf("%d\n%d\n", cnt1, cnt2);
	return 0;
}