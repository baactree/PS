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
int R, C;
int max_value;
vector<pii> cn, pn;
vector<vector<int> > edge;
int trip[100][50][50];
char mat[50][51];
int matched[100];
bool check[100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && x < R&&y >= 0 && y < C;
}
bool dfs(int now) {
	if (check[now])
		return false;
	check[now] = true;
	for (int i = 0; i < edge[now].size(); i++) {
		int there = edge[now][i];
		if (matched[there] == -1 || dfs(matched[there])) {
			matched[there] = now;
			return true;
		}
	}
	return false;
}
void bfs(int idx,int x, int y) {
	queue<pii> q;
	q.push({ x,y });
	trip[idx][x][y] = 0;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty) && mat[tx][ty] != 'X'&&trip[idx][tx][ty] == -1) {
				trip[idx][tx][ty] = trip[idx][nx][ny] + 1;
				max_value = max(max_value, trip[idx][tx][ty]);
				q.push({ tx,ty });
			}
		}
	}
}
extern inline bool possi(int d) {
	edge.clear();
	edge.resize(cn.size());
	for (int i = 0; i < cn.size(); i++) {
		for (int j = 0; j < pn.size(); j++) {
			int tx = pn[j].first;
			int ty = pn[j].second;
			if (trip[i][tx][ty]!=-1&&trip[i][tx][ty] <= d) 
				edge[i].push_back(j);
		}
	}
	memset(matched, -1, sizeof(matched));
	int ret = 0;
	for (int i = 0; i < cn.size(); i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i))
			ret++;
	}
	return ret == cn.size();
}
int main() {
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", mat[i]);
	for(int i=0;i<R;i++)
		for (int j = 0; j < C; j++) {
			if (mat[i][j] == 'C')
				cn.push_back({ i,j });
			else if (mat[i][j] == 'P')
				pn.push_back({ i,j });
		}
	memset(trip, -1, sizeof(trip));
	for (int i = 0; i < cn.size(); i++) {
		int nx = cn[i].first;
		int ny = cn[i].second;
		bfs(i, nx, ny);
	}
	int ans = -1;
	int le, ri, mid;
	le = 0;
	ri = max_value;
	while (ri >= le) {
		mid = (le + ri) / 2;
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