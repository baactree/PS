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
char mat[15][15];
int N;
ll solve(int x) {
	if (x == N)
		return 1;
	char temp[15][15];
	memcpy(temp, mat, sizeof(mat));
	ll ret = 0;
	for(int i=0;i<N;i++)
		if (!mat[x][i]) {
			for (int j = x; j < N; j++)
				mat[j][i] = 1;
			for (int j = 1; j + x < N&&i + j < N; j++)
				mat[x + j][i + j] = 1;
			for (int j = 1; j + x < N&&i - j >= 0; j++)
				mat[x + j][i - j] = 1;
			ret+=solve(x + 1);
			memcpy(mat, temp, sizeof(mat));
		}
	return ret;
}
int main() {
	scanf("%d", &N);
	printf("%lld\n", solve(0));
	return 0;
}