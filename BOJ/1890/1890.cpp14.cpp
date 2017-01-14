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
ll cache[100][100];
ll solve(int x, int y) {
	if (x >= N || y >= N)
		return 0;
	if (x == N - 1 && y == N - 1)
		return 1;
	ll &ret = cache[x][y];
	if (ret != -1)
		return ret;
    ret=0;
    ret=solve(x+mat[x][y],y);
    ret+=solve(x,y+mat[x][y]);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);
	printf("%lld\n", solve(0, 0));
	return 0;
}