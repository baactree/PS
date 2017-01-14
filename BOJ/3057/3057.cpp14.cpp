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
	int x, y, cnt;
	Node(int x, int y, int cnt) :x(x), y(y), cnt(cnt) {}
};
int N, M;
int mat[305][305];
queue<Node> q;
bool possi(int x, int y, int cnt) {
	if (x<1 || y<1 || x + cnt>N + 1 || y + cnt>M + 1)
		return false;
	for (int i = 0; i < cnt; i++) {
		if (mat[x][y + i] != mat[x + cnt - 1][y + cnt - 1 - i])
			return false;
		if (mat[x + i][y] != mat[x + cnt - 1 - i][y + cnt - 1])
			return false;
	}
	return true;
}
int main() {
	memset(mat, -1, sizeof(mat));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &mat[i][j]);
			q.push({ i,j,1 });
		}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++) {
			if (mat[i][j] == mat[i + 1][j + 1] && mat[i][j + 1] == mat[i + 1][j])
				q.push({ i,j,2 });
		}
	int ans = -1;
	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int ncnt = q.front().cnt;
		q.pop();
        ans=max(ans,ncnt);
		int tx = nx - 1;
		int ty = ny - 1;
		int tcnt = ncnt + 2;
		if (possi(tx, ty, tcnt))
			q.push({ tx,ty,tcnt });
	}
	printf("%d\n", ans==1?-1:ans);
	return 0;
}