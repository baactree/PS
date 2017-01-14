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
	reverse(all(b));
	vector<int> ans;
	for (int i = 0; i < min(a.size(), b.size()); i++)
		ans.push_back(a[i] + b[i] - '0' - '0');
	for (int i = min(a.size(), b.size()); i < max(a.size(), b.size()); i++)
		ans.push_back(a.size() < b.size() ? b[i] - '0' : a[i] - '0');
	reverse(all(ans));
	for (auto i : ans)
		printf("%d", i);
	printf("\n");
	return 0;
}