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
string solve(string &a, string &b) {
	vector<int> cnt(26, 0);
	for (int i = 0; i < a.size(); i++)
		cnt[a[i] - 'a']++;
	for (int i = 0; i < b.size(); i++)
		cnt[b[i] - 'a']--;
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0)
			return "different";
	return "same";
}
int main() {
	int tc = 1;
	while (true) {
		string a, b;
		cin >> a >> b;
		if (a == "END"&&b == "END")
			break;
		cout << "Case " << tc << ": " << solve(a,b) << "\n";
		tc++;
	}
	return 0;
}