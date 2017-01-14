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
int mat[101][101];
int cnt;
int group[101];
void dfs(int v) {
	group[v] = cnt;
	for (int i = 1; i <= N; i++)
		if (mat[v][i]==1 && group[i] == -1)
			dfs(i);
}
int main() {
	scanf("%d%d", &N, &M);
	memset(mat, 0x3f, sizeof(mat));
	memset(group, -1, sizeof(group));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b] = mat[b][a] = 1;
	}
	for (int i = 1; i <= N; i++)
		mat[i][i] = 0;
	for (int i = 1; i <= N; i++)
		if (group[i] == -1) {
			dfs(i);
			cnt++;
		}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	vector<int> ans;
	for (int k = 0; k < cnt; k++) {
		int min_value = INF;
		int idx;
		for (int i = 1; i <= N; i++) {
			if (group[i] == k) {
				int max_value = 0;
				for (int j = 1; j <= N; j++)
					if (group[j] == k)
						max_value = max(max_value, mat[i][j]);
				if (max_value < min_value) {
					min_value = max_value;
					idx = i;
				}
			}
		}
		ans.push_back(idx);
	}
	sort(all(ans));
	printf("%d\n", cnt);
	for (auto i : ans)
		printf("%d\n", i);
	return 0;
}