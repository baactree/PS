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
struct Node {
	int z, x, y;
	Node(int z,int x,int y):z(z),x(x),y(y){}
};
int L, R, C;
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };
int dz[6] = { -1,1,0,0,0,0 };
char mat[30][30][31];
int dp[30][30][30];
extern inline bool safe(int z, int x, int y) {
	return z >= 0 && z < L&&x >= 0 && x < R&&y >= 0 && y < C;
}
int main() {
	while (true) {
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0)
			break;
		queue<Node> q;
		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++) {
				scanf("%s", mat[i][j]);
				for (int k = 0; k < C; k++)
					if (mat[i][j][k] == 'S') {
						q.push({ i,j,k });
						dp[i][j][k] = 0;
					}
			}
		int ans = -1;
		while (!q.empty()) {
			int nz = q.front().z;
			int nx = q.front().x;
			int ny = q.front().y;
			int ncnt = dp[nz][nx][ny];
			q.pop();
			if (mat[nz][nx][ny] == 'E') {
				ans = ncnt;
				break;
			}
			for (int i = 0; i < 6; i++) {
				int tz = nz + dz[i];
				int tx = nx + dx[i];
				int ty = ny + dy[i];
				if (safe(tz, tx, ty) && mat[tz][tx][ty] != '#'&&dp[tz][tx][ty] == -1) {
					dp[tz][tx][ty] = ncnt + 1;
					q.push({ tz,tx,ty });
				}
			}
		}
		if (ans == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
}