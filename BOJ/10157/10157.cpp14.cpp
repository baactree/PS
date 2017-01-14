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
bool mat[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M, K;
bool safe(int x, int y) {
	return x > 0 && x <= N&&y > 0 && y <= M;
}
int main() {
	scanf("%d%d%d", &M, &N, &K);
	if (K > N*M) {
		printf("0\n");
		return 0;
	}
	int x, y;
	x = y = 1;
	mat[x][y] = true;
	K--;
	int dir = 0;
	while (K--) {
		int tx = x + dx[dir];
		int ty = y + dy[dir];
		if (!safe(tx, ty) || mat[tx][ty]) {
			dir++;
			dir %= 4;
			tx = x + dx[dir];
			ty = y + dy[dir];
		}
		mat[tx][ty] = true;
		x = tx;
		y = ty;
	}
	printf("%d %d\n", y, x);
	return 0;
}