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
char mat[50][51];
int ans_mat[50][51];
int now[50][51];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}
void solve(int x, int y, int n) {
	memset(now, -1, sizeof(now));
	queue<pair<int, int> >q;
	q.push({ x,y });
	now[x][y] = 0;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty) && now[tx][ty] == -1) {
				now[tx][ty] = now[nx][ny] + 1;
				q.push({ tx,ty });
			}
		}
	}
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++) {
			if (now[i][j] == -1)
				ans_mat[i][j] = INF;
			else
				ans_mat[i][j] += ceil((double)now[i][j] / n);
		}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	bool flag = false;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (mat[i][j] >= '1'&&mat[i][j] <= '9') {
				solve(i, j, mat[i][j] - '0');
				flag = true;
			}
		}
	int ans = INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans = min(ans, ans_mat[i][j]);
	printf("%d\n", flag&&ans < INF ? ans : -1);
	return 0;
}