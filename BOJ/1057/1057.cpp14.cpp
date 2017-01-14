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
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	A--; B--;
	int ans = 0;
	while (N!=1) {
		ans++;
		if (A/ 2 == B / 2)
			break;
		A >>= 1;
		B >>= 1;
		if (N & 1) {
			N /= 2;
			N++;
		}
		else
			N /= 2;
	}
	printf("%d\n", ans);
	return 0;
}