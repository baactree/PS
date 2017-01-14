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
	string a, b;
	cin >> a >> b;
	reverse(all(a));
	while (a.size() != 1 && a[a.size() - 1] == '0')
		a.pop_back();
	reverse(all(b));
	while (b.size() != 1 && b[b.size() - 1] == '0')
		b.pop_back();
	if (a.size() > b.size())
		swap(a, b);

	int cnt = b.size() - a.size();
	for (int i = 0; i < cnt; i++)
		a += "0";

	string ans = "";
	int pre = 0;
	for (int i = 0; i < b.size(); i++) {
		int now = a[i] - '0' + b[i] - '0' + pre;
		if (now == 0)
			ans += "0";
		else if (now == 1) {
			ans += "1";
			pre = 0;
		}
		else if (now == 2) {
			ans += "0";
			pre = 1;
		}
		else if (now == 3) {
			ans += "1";
			pre = 1;
		}
	}
	if (pre == 1)
		ans += "1";
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}