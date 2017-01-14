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
int N;
int Map[100][100];
int dx[2] = { 1,1 };
int dy[2] = { 1,-1 };
int id[2][100][100];
int cnt[2];
bool mat[2000][2000];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < N;
}
void makegraph() {
	cnt[0] = cnt[1] = 0;
	memset(id, -1, sizeof(id));
	memset(mat, 0, sizeof(mat));
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (Map[i][j] == 0&&id[k][i][j] == -1) {
					int x = i;
					int y = j;
					while (safe(x, y) && Map[x][y] == 0) {
						id[k][x][y] = cnt[k];
						x += dx[k];
						y += dy[k];
					}
					cnt[k]++;
				}
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 0)
				mat[id[0][i][j]][id[1][i][j]] = true;
}
bool trip[2000];
int matched[2000];
bool dfs(int v) {
	if (trip[v])
		return false;
	trip[v] = true;
	for (int i = 0; i < cnt[1]; i++)
		if (mat[v][i])
			if (matched[i] == -1 || dfs(matched[i])) {
				matched[i] = v;
				return true;
			}
	return false;
}
int solve() {
	int ret = 0;
	memset(matched, -1, sizeof(matched));
	for (int i = 0; i < cnt[0]; i++) {
		memset(trip, 0, sizeof(trip));
		if (dfs(i))
			ret++;
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		Map[x - 1][y - 1] = 1;
	}
	makegraph();
	printf("%d\n", solve());
	return 0;
}