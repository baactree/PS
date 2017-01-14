/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
bool prime(int n) {
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;
	return true;
}
int main() {
	int N, M;
	cin >> N >> M;
	int sum = 0;
	int ans = INF;
	for (int i = N; i <= M; i++) {
		if (prime(i)) {
			sum += i;
			ans = min(ans, i);
		}
	}
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, ans);
	return 0;
}