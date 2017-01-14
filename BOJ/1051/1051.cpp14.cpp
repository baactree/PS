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
int mat[50][50];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &mat[i][j]);
	for (int k = min(N, M); k >= 0; k--) {
		for(int i=0;i<=N-k;i++)
			for (int j = 0; j <= M - k; j++) {
				int n = mat[i][j];
				if (n == mat[i + k - 1][j] && n == mat[i][j + k - 1]
					&& n == mat[i + k - 1][j + k - 1]) {
					printf("%d\n", k*k);
					return 0;
				}
			}
	}
	return 0;
}