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
int mat[15][15];
int cache[10][15][1 << 15];
int solve(int price,int idx, int state) {
	int &ret = cache[price][idx][state];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (idx == i)
			continue;
		if (state&(1 << i))
			continue;
		if (mat[idx][i] >= price)
			ret = max(ret, solve(mat[idx][i], i, state | (1 << i))+1);
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &mat[i][j]);
	printf("%d\n", solve(0, 0, 1)+1);
	return 0;
}