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
int count(int i) {
	string a = to_string(i);
	int ret = 0;
	for (int j = 0; j < a.size(); j++)
		if (a[j] == '0')
			ret++;
	return ret;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int N, M;
		scanf("%d%d", &N, &M);
		int ans = 0;
		for (int i = N; i <= M; i++)
			ans += count(i);
		printf("%d\n",ans);
	}
	return 0;
}