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
int par[200];
int N;
vector<pii> arr;
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void merge(int x, int y) {
	par[find(y)] = find(x);
}
bool disjoint(const pii& a, const pii &b) {
	return (abs(a.first - b.first) + abs(a.second - b.second)) <= 20 * 50;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		scanf("%d", &N);
		N += 2;
		arr = vector<pii>(N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &arr[i].first, &arr[i].second);
		for (int i = 0; i < N; i++)
			par[i] = i;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (disjoint(arr[i], arr[j]))
					merge(i, j);
			}
		if (find(0) == find(N - 1))
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}