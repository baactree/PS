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
	int x, y, z;
	Node(int x,int y,int z):x(x),y(y),z(z){}
};
int N, M, H;
int n;
int mat[100][100][100];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
extern inline bool safe(int x, int y, int z) {
	return min(x, min(y, z)) >= 0 && x < N&&y < M&&z < H;
}
int main() {
	queue<Node> q;
	scanf("%d%d%d", &M, &N, &H);
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				scanf("%d", &mat[i][j][k]);
				if (mat[i][j][k] == 0)
					n++;
				else if (mat[i][j][k] == 1)
					q.push({ i,j,k });
			}
	int ans = 0;
	while (!q.empty()) {
		if (n == 0)
			break;
		ans++;
		int s = q.size();
		while (s--) {
			int nx = q.front().x;
			int ny = q.front().y;
			int nz = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int tx = nx + dx[i];
				int ty = ny + dy[i];
				int tz = nz + dz[i];
				if (safe(tx, ty, tz) && mat[tx][ty][tz] == 0) {
					mat[tx][ty][tz] = 1;
					n--;
					q.push({ tx,ty,tz });
				}
			}
		}
	}
	printf("%d\n", n != 0 ? -1 : ans);
	return 0;
}