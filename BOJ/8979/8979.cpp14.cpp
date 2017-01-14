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
struct Node {
	int a, b, c, d;
	const bool operator < (const Node& rhs)const {
		if (b == rhs.b) {
			if (c == rhs.c)
				return d > rhs.d;
			return c > rhs.c;
		}
		return b > rhs.b;
	}
};
Node arr[1000];
int N, K;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d);
	}
	sort(arr, arr + N);
	int ans;
	for (int i = 0; i < N; i++) {
		if (arr[i].a == K) {
			ans = i + 1;
			break;
		}
	}
	for (int i = ans - 1; i > 0; i--) {
		if (arr[i].b == arr[i - 1].b&&arr[i].c == arr[i - 1].c&&arr[i].d == arr[i - 1].d)
			ans--;
		else
			break;
	}
	printf("%d\n", ans);
	return 0;
}