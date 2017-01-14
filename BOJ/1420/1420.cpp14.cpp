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
char mat[100][101];
int c[100][100][5][2];
int f[100][100][5][2];
bool trip[100][100][2];
pii K, H;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}
bool possi() {
	for (int i = 0; i < 4; i++) {
		int nx = K.first + dx[i];
		int ny = K.second + dy[i];
		if (safe(nx, ny) && mat[nx][ny] == 'H')
			return true;
	}
	return false;
}
int dfs(int x, int y, bool in_out,int amount) {
	if (trip[x][y][in_out])
		return 0;
	trip[x][y][in_out] = true;
	if (!in_out&&mat[x][y] == 'H')
		return amount;
	if (!in_out) {
		if (c[x][y][4][in_out] - f[x][y][4][in_out] > 0) {
			int temp = min(amount, c[x][y][4][in_out] - f[x][y][4][in_out]);
			if (temp = dfs(x, y, 1, temp)) {
				f[x][y][4][0] += temp;
				f[x][y][4][1] -= temp;
				return temp;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (safe(nx, ny) && mat[nx][ny] != '#'&&c[x][y][i][in_out] - f[x][y][i][in_out] > 0) {
				int temp = min(amount, c[x][y][i][in_out] - f[x][y][i][in_out]);
				if (temp = dfs(nx, ny, 1, temp)) {
					f[x][y][i][in_out] += temp;
					f[nx][ny][3 - i][1] -= temp;
					return temp;
				}
			}
		}
		return 0;
	}
	if (c[x][y][4][in_out] - f[x][y][4][in_out] > 0) {
		int temp = min(amount, c[x][y][4][in_out] - f[x][y][4][in_out]);
		if (temp = dfs(x, y, 0, temp)) {
			f[x][y][4][1] += temp;
			f[x][y][4][0] -= temp;
			return temp;
		}
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && mat[nx][ny] != '#'&&c[x][y][i][in_out] - f[x][y][i][in_out] > 0) {
			int temp = min(amount, c[x][y][i][in_out] - f[x][y][i][in_out]);
			if (temp=dfs(nx, ny, 0,temp)) {
				f[x][y][i][in_out]+=temp;
				f[nx][ny][3 - i][0]-=temp;
				return temp;
			}
		}
	}
	return 0;
}
int nf() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 4; k++) {
				c[i][j][k][1] = INF;
			}
			c[i][j][4][0] = 1;
		}
	int totalflow = 0;
	while (true) {
		memset(trip, 0, sizeof(trip));
		int amount = dfs(K.first, K.second, 1, INF);
		if (amount == 0)
			break;
		totalflow += amount;
	}
	return totalflow;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &mat[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 'K')
				K.first = i, K.second = j;
			else if (mat[i][j] == 'H')
				H.first = i, H.second = j;
		}
	int ans = nf();
	printf("%d\n", ans>=INF?-1:ans);
	return 0;
}