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
char mat[50][51];
short dp[4][50][50][1 << 10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	dp[K][0][0][1023] = mat[0][0]=='.'?0:mat[0][0]-'0';
	for(int k=K;k>=0;k--)
		for(int x=0;x<N;x++)
			for (int y = 0; y < M; y++) {
				for (int s = 0; s < 1 << 10; s++) {
                    if(dp[k][x][y][s]==-1)
                        continue;
					int d[4];
					for (int i = 0; i < 4; i++) {
						d[i] = 0;
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && nx < N&&ny >= 0 && ny < M&&mat[nx][ny] != '#'&&mat[nx][ny] != '.')
							d[i] = mat[nx][ny] - '0';
					}
					int temp = s;
					int nx = x;
					int ny = y;
					for (int i = 0; i < 5; i++) {
						nx = nx - dx[temp & 3];
						ny = ny - dy[temp & 3];
						for (int k = 0; k < 4; k++) {
							if (nx == x + dx[k] && ny == y + dy[k]) {
								d[k] = 0;
							}
						}
						temp >>= 2;
					}
					if(x+1!=N&&mat[x+1][y]!='#')
						dp[k][x+1][y][((s << 2) | 1) & 1023] = max(dp[k][x+1][y][((s<<2)|1)&1023], (short)(dp[k][x][y][s]+d[1]));
					if(y+1!=M&&mat[x][y+1]!='#')
						dp[k][x][y+1][((s << 2) | 3) & 1023] = max(dp[k][x][y + 1][((s << 2) | 3) & 1023], (short)(dp[k][x][y][s]+d[3]));
					if (k != 0) {
						if(x!=0&&mat[x-1][y]!='#')
							dp[k-1][x-1][y][((s << 2) | 0) & 1023] = max(dp[k - 1][x - 1][y][((s << 2) | 0) & 1023], (short)(dp[k][x][y][s]+d[0]));
						if(y!=0&&mat[x][y-1]!='#')
							dp[k - 1][x][y-1][((s << 2) | 2) & 1023] = max(dp[k - 1][x ][y-1][((s << 2) | 2) & 1023], (short)(dp[k][x][y][s]+d[2]));
					}
				}
			}
	short ans = 0;
	for (int k = 0; k <= K; k++)
		for (int s = 0; s < 1 << 10; s++)
			ans = max(ans, dp[k][N-1][M-1][s]);
	printf("%d\n", ans);
	return 0;
}