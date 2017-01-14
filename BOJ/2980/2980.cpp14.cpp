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
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
vector<pii> arr[1001];
int N, L;
int search(int loc, int t) {
	if (loc == L)
		return t;
	if (arr[loc].empty())
		return search(loc + 1, t + 1);
	int cycle = arr[loc][0].first + arr[loc][0].second;
	if (t%cycle >= arr[loc][0].first)
		return search(loc + 1, t + 1);
	return search(loc, t + 1);
}
int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) {
		int loc;
		int a, b;
		scanf("%d", &loc);
		scanf("%d%d", &a, &b);
		arr[loc].push_back({ a,b });
	}
	printf("%d\n", search(0, 0));
	return 0;
}