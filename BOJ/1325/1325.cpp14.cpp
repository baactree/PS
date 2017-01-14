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
vector<vector<int> >edge;
vector<int> hack;
vector<int> ans;
vector<int> trip;
int dfs(int here, int cnt) {
	int ret = 1;
	trip[here] = cnt;
	for (int i = 0; i < edge[here].size(); i++) {
		int there = edge[here][i];
		if (trip[there] == cnt)
			continue;
		ret += dfs(there, cnt);
	}
	return ret;
}
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	edge = vector<vector<int> >(N + 1);
	hack = trip = vector<int>(N + 1, -1);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		edge[b].push_back(a);
	}
	int max_value = -1;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int sum=dfs(i, cnt);
		cnt++;
		if (max_value < sum) {
			max_value = sum;
			ans.clear();
			ans.push_back(i);
		}
		else if (max_value == sum)
			ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}