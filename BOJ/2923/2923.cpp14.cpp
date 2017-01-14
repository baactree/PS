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
int A[101];
int B[101];
int cntA[101];
int cntB[101];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		A[a]++;
		B[b]++;
		for (int i = 1; i <= 100; i++) {
			cntA[i] = A[i];
			cntB[i] = B[i];
		}

		int le = 1;
		int ri = 100;
		int k = 0;
		int max_value = 0;
		while (k != i) {
			while (cntA[le] == 0)
				le++;
			while (cntB[ri] == 0)
				ri--;
			if (cntA[le] > cntB[ri]) {
				cntA[le] -= cntB[ri];
				k += cntB[ri];
				cntB[ri] = 0;
				max_value = max(max_value, le + ri);
			}
			else {
				cntB[ri] -= cntA[le];
				k += cntA[le];
				cntA[le] = 0;
				max_value = max(max_value, le + ri);
			}
		}
		printf("%d\n", max_value);
	}
	return 0;
}