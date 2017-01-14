/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int par[300001];
bool trip[300001];
int N, M;
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	par[find(x)] = find(y);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
		par[i] = i;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &a, &b);
		if (!trip[a]) {
			trip[a] = true;
			merge(a, b);
			printf("LADICA\n");
		}
		else if (!trip[b]) {
			trip[b] = true;
			merge(b, a);
			printf("LADICA\n");
		}
		else if (!trip[find(a)]) {
			trip[find(a)] = true;
			merge(a, b);
			printf("LADICA\n");
		}
		else if (!trip[find(b)]) {
			trip[find(b)] = true;
			merge(b, a);
			printf("LADICA\n");
		}
		else
			printf("SMECE\n");
	}
	return 0;
}

