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
int mat[9][9];
int r[9];
int c[9];
int m[9];
void solve(int x, int y) {
	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", mat[i][j]);
			printf("\n");
		}
		exit(1);
		return;
	}
	if (y == 9) {
		solve(x + 1, 0);
		return;
	}
	if (mat[x][y] != 0) {
		solve(x, y + 1);
		return;
	}
	for (int n = 1; n < 10; n++) {
		if (r[x] & (1 << n))
			continue;
		if (c[y] & (1 << n))
			continue;
		if (m[(x / 3) * 3 + y / 3] & (1 << n))
			continue;
		mat[x][y] = n;
		r[x] |= (1 << n);
		c[y] |= (1 << n);
		m[(x / 3) * 3 + y / 3] |= (1 << n);
		solve(x, y + 1);
		mat[x][y] = 0;
		r[x] &= ~(1 << n);
		c[y] &= ~(1 << n);
		m[(x / 3) * 3 + y / 3] &= ~(1 << n);
	}
}
int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &mat[i][j]);
			r[i] |= (1 << mat[i][j]);
			c[j] |= (1 << mat[i][j]);
			m[(i / 3) * 3 + j / 3] |= (1 << mat[i][j]);
		}
	solve(0, 0);
	return 0;
}