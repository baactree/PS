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
struct Tree {
	int n;
	int m;
	vector<vector<int> >tree;
	Tree(int n, int m) :n(n + 1), m(m + 1) {
		tree = vector<vector<int> >(n + 1, vector<int>(m + 1));
	}
	void update(int x, int y, int value) {
		int y1;
		x++; y++;
		while (x < n) {
			y1 = y;
			while (y1 < m) {
				tree[x][y1] += value;
				y1 += (y1&-y1);
			}
			x += (x&-x);
		}
	}
	int query(int x, int y) {
		x++; y++;
		int sum = 0;
		int y1;
		while (x > 0) {
			y1 = y;
			while (y1 > 0) {
				sum += tree[x][y1];
				y1 -= (y1&-y1);
			}
			x -= (x&-x);
		}
		return sum;
	}
};
int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	Tree tree1(N * 2 + 1, N * 2 + 1);
	Tree tree2(N * 2 + 1, N * 4 + 1);
	for (int i = 0; i < Q; i++) {
		int a, b, c, d;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d%d", &b, &c, &d);
			tree1.update(b - d + N, c - d + N, 1);
			tree1.update(b - d + N, c + N, -1);
			tree1.update(b + d + 1 + N, c + N, -1);
			tree1.update(b + d + 1 + N, c + d + 1 + N, 1);
			tree2.update(c - d + N, b + 1 - (c - d) + 2 * N, -1);
			tree2.update(c + N, b + d + 1 - c + 2 * N, 1);
			tree2.update(c + N, b - d - c + 2 * N, 1);
			tree2.update(c + d + 1 + N, b + 1 - (c + d + 1) + 2 * N, -1);
		}
		else {
			scanf("%d%d", &b, &c);
			printf("%d\n", tree1.query(b + N, c + N) + tree2.query(c + N, b - c + 2 * N));
		}
	}
	return 0;
}