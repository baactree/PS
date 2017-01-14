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
int mat[101][101];
int st, fi;
int main() {
	memset(mat, 0x3f, sizeof(mat));
	scanf("%d%d%d%d", &N, &st, &fi, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b] = mat[b][a] = 1;
	}
	for (int i = 1; i <= N; i++)
		mat[i][i] = 0;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	printf("%d\n", mat[st][fi]==INF?-1:mat[st][fi]);
	return 0;
}