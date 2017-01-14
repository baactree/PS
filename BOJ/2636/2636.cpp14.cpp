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
int mat[100][100];
bool trip[100][100];
bool melt[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}
void dfs(int x, int y) {
	trip[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && mat[nx][ny] == 0 && !trip[nx][ny])
			dfs(nx, ny);
		if (safe(nx, ny) && mat[nx][ny] == 1)
			melt[nx][ny] = 1;
	}
	return;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &mat[i][j]);
	int cnt = 0;
	int ans = 0;
	while (true) {
		memset(trip, 0, sizeof(trip));
		memset(melt, 0, sizeof(melt));
		int temp = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (mat[i][j] == 1)
					temp++;
		if (temp == 0)
			break;
		ans = temp;
		dfs(0, 0);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (melt[i][j])
					mat[i][j] = 0;
		cnt++;
	}
	printf("%d\n%d\n", cnt, ans);
}