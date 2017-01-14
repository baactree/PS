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
char mat[1000][1001];
int trip[1000][1000];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
bool safe(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < M;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	queue<pii> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (mat[i][j] != '.')
				q.push({ i,j });
	int ans = 0;
	queue<pii> qq;
	while (!q.empty()) {
		int tt = q.size();
		bool flag = false;
		for (int i = 0; i < tt; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (mat[x][y] == '.')
				continue;
			int cnt = 0;
			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (safe(nx, ny) && mat[nx][ny] == '.')
					cnt++;
			}
			if (cnt >= mat[x][y]-'0') {
				flag = true;
				qq.push({ x,y });
				for (int j = 0; j < 8; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];
					if (safe(nx, ny) && mat[nx][ny] != '.'&&trip[nx][ny]!=ans+1) {
						trip[nx][ny] = ans+1;
						q.push({ nx,ny });
					}
				}
			}
		}
		if (!flag)
			break;
		while (!qq.empty()) {
			int x = qq.front().first;
			int y = qq.front().second;
			qq.pop();
			mat[x][y] = '.';
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}