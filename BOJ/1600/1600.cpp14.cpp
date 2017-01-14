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
	int x, y, k, cnt;
	Node(int x,int y,int k,int cnt):x(x),y(y),k(k),cnt(cnt){}
};
bool trip[200][200][31];
int mat[200][200];
int N, M, K;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
int kx[4] = { -1,1,0,0 };
int ky[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}

int main() {
	scanf("%d%d%d", &K, &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &mat[i][j]);
	queue<Node> q;
	q.push({ 0,0,K,0 });
	int ans = INF;
	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int nk = q.front().k;
		int ncnt = q.front().cnt;
		q.pop();
		if (nx == N - 1 && ny == M - 1) {
			ans = ncnt;
			break;
		}
		if (nk > 0) {
			for (int i = 0; i < 8; i++) {
				int tx = nx + dx[i];
				int ty = ny + dy[i];
				if (safe(tx, ty) && !mat[tx][ty] && !trip[tx][ty][nk - 1]) {
					trip[tx][ty][nk - 1] = true;
					q.push({ tx,ty,nk - 1,ncnt + 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int tx = nx + kx[i];
			int ty = ny + ky[i];
			if (safe(tx, ty) && !mat[tx][ty] && !trip[tx][ty][nk]) {
				trip[tx][ty][nk] = true;
				q.push({ tx,ty,nk,ncnt + 1 });
			}
		}
	}
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}