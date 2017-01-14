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
vector<pair<int, pair<int, int>>> ans;
int N;
int g[101];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ans.push_back({ -c,{a,b} });
	}
	sort(all(ans));
	int cnt = 0;
	for (int i = 0; i < ans.size()&&cnt<3; i++) {
		if (g[ans[i].second.first] < 2) {
			g[ans[i].second.first]++;
			printf("%d %d\n", ans[i].second.first, ans[i].second.second);
			cnt++;
		}
	}
	return 0;
}