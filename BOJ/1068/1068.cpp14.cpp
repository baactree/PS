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
int N, C;
vector<int> edge[50];
int solve(int n) {
	int ret = 0;
	for (int i = 0; i < edge[n].size(); i++) {
		int there = edge[n][i];
		if (there == C)
			continue;
		ret += solve(there);
	}
	if (ret == 0)
		return 1;
	return ret;
}
int main(){
	scanf("%d", &N);
	int root;
	for (int i = 0; i < N; i++) {
		int p;
		scanf("%d", &p);
		if (p == -1) {
			root = i;
			continue;
		}
		edge[p].push_back(i);
	}
	scanf("%d", &C);
	printf("%d\n", C==root?0:solve(root));
	return 0;
}