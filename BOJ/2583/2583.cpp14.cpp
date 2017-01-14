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
int N, M, K;
bool trip[100][100];
int mat[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}
void paint(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			mat[i][j] = 1;
}
int dfs(int x, int y) {
	trip[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && mat[nx][ny] == 0 && !trip[nx][ny])
			ret += dfs(nx, ny);
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		paint(b, a, d, c);
	}
	vector<int> ans;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if (mat[i][j] == 0 && !trip[i][j]) 
				ans.push_back(dfs(i, j));
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}