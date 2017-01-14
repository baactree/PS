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
int N, M;
int main(){
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &N, &M);
		printf("1\n");
		for (int i = 0; i < M; i++) {
			if (i & 1) {
				for (int j = N - 2; j >= 0; j--)
					printf("(%d,%d)\n", j, i);
			}
			else {
				for (int j = 0; j < N - 1; j++)
					printf("(%d,%d)\n", j, i);
			}
		}
		for (int j = M - 1; j >= 0; j--)
			printf("(%d,%d)\n", N - 1, j);
	}
	return 0;
}