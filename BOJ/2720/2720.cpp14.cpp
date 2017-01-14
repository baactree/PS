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
	int tc;
	scanf("%d", &tc);
	int pp[4] = { 25,10,5,1 };
	while (tc--) {
		int N;
		scanf("%d", &N);
		int cnt[4] = { 0, };
		for (int i = 0; i < 4; i++)
			while (N >= pp[i])
				cnt[i] = N / pp[i], N %= pp[i];
		for (int i = 0; i < 4; i++)
			printf("%d ", cnt[i]);
		printf("\n");
	}
	return 0;
}