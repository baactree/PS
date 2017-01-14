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
char mat[300][300];
int trip[300][300];
bool check[100000];
int N, M, K;
double k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N * 2 + 1 && y < M * 2 + 1;
}
void dfs(int x, int y, int cnt) {
	trip[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && (mat[nx][ny] == '.' || mat[nx][ny] == 'B') && trip[nx][ny] == -1)
			dfs(nx, ny, cnt);
	}
}
int tx[4] = { -1 ,-1,1,1};
int ty[4] = { -1,1,1,-1 };
int search(int x, int y, int dir) {
	if (x == N * 2 && (dir == 3 || dir == 2))
		return 0;
	if (x == 0 && (dir == 0 || dir == 1)) {
		if (dir == 0)
			return search(x, y, 3);
		else
			return search(x, y, 2);
	}
	if (y == 0 && (dir == 0 || dir == 3)) {
		if (dir == 0)
			return search(x, y, 1);
		else
			return search(x, y, 2);
	}
	if (y == M * 2 && (dir == 1 || dir == 2)) {
		if (dir == 1)
			return search(x, y, 0);
		else
			return search(x, y, 3);
	}
	for (int i = 0; i < 4; i++) {
		if (dir == i) {
			int nx = x + tx[i];
			int ny = y + ty[i];
			int ret = 0;
			if (mat[nx][ny] == 'B'||mat[nx][ny]=='.') {
				int cnt = trip[nx][ny];
				if (!check[cnt]) {
					ret = 1;
					check[cnt] = true;
				}
			}
			else {
				if (mat[x][y] == '-') {
					int kx = x;
					int ky = y;
					if (dir == 0 || dir == 1)
						kx--;
					if (dir == 2 || dir == 3)
						kx++;
					if (mat[kx][ky] == 'B' || mat[kx][ky] == '.') {
						int cnt = trip[kx][ky];
						if (!check[cnt]) {
							ret = 1;
							check[cnt] = true;
						}
					}
				}
				else if (mat[x][y] == '|') {
					int kx = x;
					int ky = y;
					if (dir == 0 || dir == 3)
						ky--;
					if (dir == 2 || dir == 1)
						ky++;
					if (mat[kx][ky] == 'B' || mat[kx][ky] == '.') {
						int cnt = trip[kx][ky];
						if (!check[cnt]) {
							ret = 1;
							check[cnt] = true;
						}
					}
				}
			}
			return search(nx, ny, dir) + ret;
		}
	}
	return INF;
}
int main() {
	memset(trip, -1, sizeof(trip));
	scanf("%d%d%lf", &M, &N, &k);
	K = k * 2 + EOD;
	for (int i = 0; i < N * 2 + 1; i++)
		scanf("%s", mat[i]);
	int cnt = 0;
	for (int i = 0; i < N * 2 + 1; i++)
		for (int j = 0; j < M * 2 + 1; j++)
			if (mat[i][j] == 'B'&&trip[i][j] == -1) {
				dfs(i, j, cnt);
				cnt++;
			}
	printf("%d\n", search(N * 2, K, 0));
	return 0;
}