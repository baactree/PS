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
int mat[200][200];
int N;
int dist[200][200];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < N&&y < N;
}
int main() {
	int tc = 1;
	while (true) {
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &mat[i][j]);
		memset(dist, 0x3f, sizeof(dist));
		dist[0][0] = mat[0][0];
		priority_queue<pair<int, pair<int, int> > >pq;
		pq.push({ -mat[0][0],{0,0} });
		while (!pq.empty()) {
			int nx = pq.top().second.first;
			int ny = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[nx][ny] < cost)
				continue;
			for (int i = 0; i < 4; i++) {
				int tx = nx + dx[i];
				int ty = ny + dy[i];
				if (safe(tx,ty)){
					int there_cost = cost + mat[tx][ty];
					if (dist[tx][ty]>there_cost) {
						dist[tx][ty] = there_cost;
						pq.push({ -there_cost,{tx,ty} });
					}
				}
			}
		}
		printf("Problem %d: %d\n", tc++,dist[N - 1][N - 1]);
	}
	return 0;
}