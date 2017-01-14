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
struct Node {
	int x, y, cnt, bk;
	Node(int x,int y,int cnt,int bk):x(x),y(y),cnt(cnt),bk(bk){}
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&&y < M);
}
bool trip[1000][1000][2];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &mat[i][j]);
	queue<Node> q;
	q.push({ 0, 0, 1, 0 });
	trip[0][0][0];
	int ans = -1;
	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int ncnt = q.front().cnt;
		int nbk = q.front().bk;
		q.pop();
		if (nx == N - 1 && ny == M - 1) {
			ans = ncnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty)&&!trip[tx][ty][nbk]) {
				if (mat[tx][ty] == 0) {
					trip[tx][ty][nbk] = true;
					q.push({ tx,ty,ncnt + 1,nbk });
				}
				else if(nbk==0){
					trip[tx][ty][nbk+1] = true;
					q.push({ tx,ty,ncnt + 1,nbk + 1 });
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}