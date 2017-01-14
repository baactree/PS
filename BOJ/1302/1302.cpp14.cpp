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
string ans;
int N;
map<string, int> m;
int main() {
	scanf("%d", &N);
	int max_value = 0;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		m[input]++;
		if (max_value < m[input]) {
			max_value = m[input];
			ans = input;
		}
		else if (max_value == m[input]) {
			ans = min(ans, input);
		}
	}
	cout << ans << endl;
	return 0;
}