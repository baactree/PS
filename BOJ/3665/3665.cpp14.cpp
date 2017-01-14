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
int mat[501][501];
int arr[500];
int par[501];
void solve(int N) {
	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (par[i]==0)
			q.push(i);
	while (!q.empty()) {
		if (q.size() >= 2) {
			printf("?\n");
			return;
		}
		int now = q.front();
		ans.push_back(now);
		q.pop();
		for (int i = 1; i <= N;i++)
			if (mat[now][i]) {
				par[i]--;
				if (par[i]==0)
					q.push(i);
			}
	}
	if (ans.size() != N) {
		printf("IMPOSSIBLE\n");
		return;
	}
	for (auto a : ans)
		printf("%d ", a);
	printf("\n");
	return;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(par, 0, sizeof(par));
		memset(mat, 0, sizeof(mat));
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++) {
				mat[arr[i]][arr[j]] = 1;
				par[arr[j]]++;
			}
		int M;
		scanf("%d", &M);
		bool flag = false;
		for (int i = 0; i < M; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (mat[b][a]) {
				mat[b][a] = 0;
				par[a]--;
				mat[a][b] = 1;
				par[b]++;
			}
			else {
				mat[a][b] = 0;
				par[b]--;
				mat[b][a] = 1;
				par[a]++;
			}
		}
		solve(N);
	}
	return 0;
}