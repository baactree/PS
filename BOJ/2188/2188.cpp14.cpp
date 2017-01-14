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
int N, M;
bool trip[201];
int matched[201];
bool mat[201][201];
bool dfs(int v) {
	if (trip[v])
		return false;
	trip[v] = true;
	for (int i = 1; i <= M;i++)
		if(mat[v][i])
			if (matched[i] == -1 || dfs(matched[i])) {
				matched[i] = v;
				return true;
			}
	return false;
}
int main(){
	memset(matched, -1, sizeof(matched));
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int there;
			scanf("%d", &there);
			mat[i][there] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(trip, 0, sizeof(trip));
		if (dfs(i))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}