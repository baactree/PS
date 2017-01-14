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
int N, M, T, D;
char mat[25][26];
int Map[25][25];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
extern inline bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < M;
}
vector<vector<int> > dijk(bool mode) {
	vector<vector<int> > ret(N, vector<int>(M, INF));
	priority_queue<pair<int, pii> > pq;
	pq.push({ 0,{ 0,0 } });
	ret[0][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int nx = pq.top().second.first;
		int ny = pq.top().second.second;
		pq.pop();
		if (ret[nx][ny] < cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (safe(tx, ty) && abs(Map[nx][ny] - Map[tx][ty]) <= T) {
				int there_cost = 1 + cost;
				if (mode) {
					if (Map[tx][ty] > Map[nx][ny])
						there_cost = cost + (Map[tx][ty] - Map[nx][ny])*(Map[tx][ty] - Map[nx][ny]);
				}
				else {
					if (Map[tx][ty] < Map[nx][ny])
						there_cost = cost + (Map[tx][ty] - Map[nx][ny])*(Map[tx][ty] - Map[nx][ny]);
				}
				if (ret[tx][ty] > there_cost) {
					ret[tx][ty] = there_cost;
					pq.push({ -there_cost,{ tx,ty } });
				}
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d%d", &N, &M, &T, &D);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (mat[i][j] >= 'A'&&mat[i][j] <= 'Z')
				Map[i][j] = mat[i][j] - 'A';
			else
				Map[i][j] = mat[i][j] - 'a' + 26;
		}
	vector<vector<int> > go = dijk(true);
	vector<vector<int> > back = dijk(false);
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (go[i][j] + back[i][j] <= D)
				ans = max(ans, Map[i][j]);
	printf("%d\n", ans);
	return 0;
}