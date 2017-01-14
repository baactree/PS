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
	int x, y, m, M;
	Node(int x,int y,int m,int M):x(x),y(y),m(m),M(M){}
};
int N;
int mat[100][100];
bool trip[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < N;
}
bool dfs(int x, int y, int m, int M) {
	if (trip[x][y])
		return false;
	trip[x][y] = true;
	if (mat[x][y]<m || mat[x][y]>M)
		return false;
	if (x == N - 1 && y == N - 1)
		return true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny))
			if (dfs(nx, ny, m, M))
				return true;
	}
	return false;
}
extern inline bool possi(int x) {
	for (int i = 0; i + x <= 200; i++){
		memset(trip, 0, sizeof(trip));
		if (dfs(0, 0, i, i + x))
			return true;
	}
	return false;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);
	int ans;
	int le, ri, mid;
	le = 0; ri = 200;
	while (ri >= le) {
		mid = (ri + le) / 2;
		if (possi(mid)) {
			ans = mid;
			ri = mid - 1;
		}
		else
			le = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}