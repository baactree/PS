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
int trip[300][300];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < N;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		memset(trip, -1, sizeof(trip));
		int sx, sy, fx, fy;
		scanf("%d%d%d%d%d", &N, &sx, &sy, &fx, &fy);
		queue<pii> q;
		q.push({ sx,sy });
		trip[sx][sy] = 0;
		int ans;
		while (!q.empty()) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			if (nx == fx&&ny == fy) {
				ans = trip[nx][ny];
				break;
			}
			for (int i = 0; i < 8; i++) {
				int tx = nx + dx[i];
				int ty = ny + dy[i];
				if (safe(tx, ty) && trip[tx][ty] == -1) {
					trip[tx][ty] = trip[nx][ny] + 1;
					q.push({ tx,ty });
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
