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
int price[6][6] = {
	{10,8,7,5,0,1},
	{8,6,4,3,0,1},
	{7,4,3,2,0,1},
	{5,3,2,2,0,1},
	{0,0,0,0,0,0},
	{1,1,1,1,0,0}
};
int N, M;
int cache[14 * 14][1 << 14];
char mat[14][15];
int solve(int idx, int state) {
	if (idx >= N*M)
		return 0;
	int &ret = cache[idx][state];
	if (ret != -1)
		return ret;
	ret = 0;
	int x = idx / M;
	int y = idx%M;
	if (y != M - 1 && !(state & 1) && !(state & 2))
		ret = max(ret, solve(idx + 2, state >> 2) + price[mat[x][y] - 'A'][mat[x][y + 1] - 'A']);
	if (x != N - 1 && !(state & 1))
		ret = max(ret, solve(idx + 1, (state >> 1) | (1 << (M - 1))) + price[mat[x][y] - 'A'][mat[x + 1][y] - 'A']);
	ret = max(ret, solve(idx + 1, state >> 1));
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	printf("%d\n", solve(0, 0));
	return 0;
}