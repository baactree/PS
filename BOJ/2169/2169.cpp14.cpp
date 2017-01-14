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
int mat[1000][1000];
int N, M;
int cache[1000][1000][3];
//하 좌 우
int search(int x, int y, int dir) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return -INF;
	if (x == N - 1 && y == M - 1)
		return mat[N - 1][M - 1];
	int &ret = cache[x][y][dir];
	if (ret != INF)
		return ret;
	ret = search(x + 1, y, 0)+mat[x][y];
	if(dir!=1)
		ret = max(ret, search(x, y + 1, 2) + mat[x][y]);
	if (dir != 2)
		ret = max(ret, search(x, y - 1, 1) + mat[x][y]);
	return ret;
}
int main() {
	memset(cache, 0x3f, sizeof(cache));
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &mat[i][j]);
	printf("%d\n", search(0, 0, 0));
	return 0;
}