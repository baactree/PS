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
const int mod = 1000007;
int N, M, C;
int cache[51][51][51][51];
int mat[51][51];
int solve(int x, int y, int c, int now) {
	if (c < 0)
		return 0;
	if (x == N&&y == M) {
		if (c == 0)
			return 1;
		return 0;
	}
	int &ret = cache[x][y][c][now];
	if (ret != -1)
		return ret;
	ret = 0;
	if (now == 0) {
		if (x != N) {
			if (mat[x + 1][y] != 0)
				ret += solve(x + 1, y, c - 1, mat[x + 1][y]);
			else
				ret += solve(x + 1, y, c, now);
			ret %= mod;
		}
		if (y != M) {
			if (mat[x][y + 1] != 0)
				ret += solve(x, y + 1, c - 1, mat[x][y + 1]);
			else
				ret += solve(x, y + 1, c, now);
			ret %= mod;
		}
		return ret;
	}
	if (x != N) {
		if (mat[x + 1][y] != 0 && now < mat[x + 1][y])
			ret += solve(x + 1, y, c - 1, mat[x + 1][y]);
		else if(mat[x+1][y]==0)
			ret += solve(x + 1, y, c, now);
		ret %= mod;
	}
	if (y != M) {
		if (mat[x][y + 1] != 0 && now < mat[x][y + 1])
			ret += solve(x, y + 1, c - 1, mat[x][y + 1]);
		else if(mat[x][y+1]==0)
			ret += solve(x, y + 1, c, now);
		ret %= mod;
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d", &N, &M, &C);
	for (int i = 0; i < C; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b] = i + 1;
	}
	for (int i = 0; i <= C; i++) {
		int ans;
		if (mat[1][1] != 0)
			ans = solve(1, 1, i - 1, mat[1][1]);
		else
			ans = solve(1, 1, i, 0);
		printf("%d ", ans);
	}
	return 0;
}