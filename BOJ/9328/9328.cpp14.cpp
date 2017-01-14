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
char mat[105][105];
int N, M;
bool trip[105][105];
char str[27];
struct Node {
	int x, y;
	int key;
	Node(int x, int y,int key) :x(x), y(y),key(key) {}
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N + 2 && y < M + 2;
}
int solve() {
	int key = 0;
	if (str[0] != '0') {
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			key|= (1 << (str[i] - 'a'));
	}
	queue<Node> q;
	trip[0][0] = true;
	q.push({ 0,0,key });
	int ret = 0;
	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int nkey = q.front().key;
		q.pop();
		if (mat[nx][ny] == '$') {
			ret++;
			mat[nx][ny] = '.';
		}
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty) && !trip[tx][ty]&&mat[tx][ty]!='*') {
				if (mat[tx][ty] >= 'A'&&mat[tx][ty] <= 'Z') {
					int idx = mat[tx][ty] - 'A';
					if (nkey&(1 << idx)) {
						mat[tx][ty] = '.';
						trip[tx][ty] = true;
						q.push({ tx,ty,nkey });
					}
				}
				else if (mat[tx][ty] >= 'a'&&mat[tx][ty] <= 'z') {
					int idx = mat[tx][ty] - 'a';
					if (nkey&(1 << idx)) {
						mat[tx][ty] = '.';
						trip[tx][ty] = true;
						q.push({ tx,ty,nkey });
					}
					else {
						memset(trip, 0, sizeof(trip));
						q = queue<Node>();
						trip[tx][ty] = true;
						q.push({ tx,ty,nkey|(1<<idx) });
						break;
					}
				}
				else {
					trip[tx][ty] = true;
					q.push({ tx,ty,nkey });
				}
			}
		}
	}
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		for (int i = 0; i < 105; i++)
			for (int j = 0; j < 105; j++)
				mat[i][j] = '.';
		memset(trip, 0, sizeof(trip));
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf("%s", &mat[i][1]);
			mat[i][M + 1] = '.';
		}
		scanf("%s", str);
		printf("%d\n", solve());
	}
	return 0;
}