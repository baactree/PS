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
string alpa[8] = { "c=","c-","d-","lj","nj","s=","z=","dz=" };
int main() {
	string str;
	cin >> str;
	str += "_";
	int ans = 0;
	for (int i = 0; i < str.size() - 3; i++) {
		for (int j = 0; j < 7; j++) {
			if (alpa[j] == string(str.begin() + i, str.begin() + i + 2)) {
				ans++;
				str[i] = '_';
				str[i + 1] = '-';
			}
		}
		if (alpa[7] == string(str.begin() + i, str.begin() + i + 3)) {
			ans++;
			str[i] = '_';
			str[i + 1] = '_';
			str[i + 2] = '_';
		}
	}
	for (int i = 0; i < str.size(); i++)
		if (str[i] >= 'a'&&str[i] <= 'z')
			ans++;
	printf("%d\n", ans);
	return 0;
}