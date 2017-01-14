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
int mat[100][100];
bool trip[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}
void dfs(int x, int y, int hight) {
	if (trip[x][y])
		return ;
	trip[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (safe(nx, ny) && mat[nx][ny] > hight)
			dfs(nx, ny, hight);
	}
;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);
	int ans = 0;
	for (int i = 0; i < 101; i++) {
		memset(trip, 0, sizeof(trip));
		int cnt = 0;
		for(int j=0;j<N;j++)
			for (int k = 0; k < N; k++) {
				if (mat[j][k] > i && !trip[j][k]) {
					dfs(j, k, i);
					cnt++;
				}
			}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}