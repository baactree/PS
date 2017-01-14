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
int p[20];
int solve(int n, int r, int c) {
	if (n == 0)
		return 0;
	if (p[n - 1] <= r) {
		if (p[n - 1] <= c)
			return p[n - 1] * p[n - 1]*3 + solve(n - 1, r - p[n -1], c - p[n -1]);
		return p[n -1] * p[n -1] * 2 + solve(n - 1, r - p[n -1], c);
	}
	if (p[n -1] <= c) {
		return p[n -1] * p[n -1] + solve(n -1, r, c - p[n -1]);
	}
	return solve(n -1, r, c);
}
int main() {
	p[0] = 1;
	for (int i = 1; i < 20; i++)
		p[i] = p[i - 1] * 2;
	int N, R, C;
	while (scanf("%d%d%d", &N, &R, &C) != EOF) {
		printf("%d\n", solve(N, R, C));
	}
	return 0;
}