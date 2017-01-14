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
string str;
int cnt[10];
int main() {
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '6' || str[i] == '9') {
			if (cnt[6] == 0 && cnt[9] == 0) {
				ans++;
				for (int j = 0; j < 10; j++)
					cnt[j]++;
			}
			cnt[6] == 0 ? cnt[9]-- : cnt[6]--;
		}
		else {
			if (cnt[str[i] - '0'] == 0) {
				ans++;
				for (int j = 0; j < 10; j++)
					cnt[j]++;
			}
			cnt[str[i] - '0']--;
		}
	}
	printf("%d\n", ans);
	return 0;
}