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
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		deque<int> dq(5);
		for (int i = 0; i < 5; i++)
			scanf("%d", &dq[i]);
		sort(dq.begin(), dq.end());
		if (dq[3] - dq[1] >= 4)
			printf("KIN\n");
		else
			printf("%d\n", dq[1] + dq[2] + dq[3]);
	}
	return 0;
}