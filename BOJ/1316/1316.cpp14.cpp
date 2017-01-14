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
bool possi(const string& arr) {
	vector<bool> check(26, 0);
	check[arr[0] - 'a'] = true;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == arr[i - 1])
			continue;
		else if (check[arr[i] - 'a'])
			return false;
		else
			check[arr[i] - 'a'] = true;
	}
	return true;
}
int main() {
	int tc;
	scanf("%d\n", &tc);
	int ans = 0;
	while (tc--) {
		string arr;
		cin >> arr;
		if (possi(arr))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}