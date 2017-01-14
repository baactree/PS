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
	vector<vector<int> >tree;
	Tree(int n) :n(n) {
		n++;
		tree = vector<vector<int> >(n, vector<int>(n));
	}
	void update(int x, int y, int value) {
		int y1;
		while (x <= n) {
			y1 = y;
			while (y1 <= n) {
				tree[x][y1] += value;
				y1 += (y1&-y1);
			}
			x += (x&-x);
		}
	}
	int query(int x, int y) {
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
int get_ans(int x1, int y1, int x2, int y2,Tree& tree) {
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);
	return tree.query(x2, y2) - tree.query(x2, y1 - 1) - tree.query(x1 - 1, y2) + tree.query(x1 - 1, y1 - 1);
}
int main(){
	int N, M;
	scanf("%d%d", &N, &M);
	vector<vector<int> > mat(N,vector<int>(N));
	Tree tree(N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int in;
			scanf("%d", &in);
			tree.update(i, j, in);
		}
	for (int i = 0; i < M; i++) {
		int a, b, c, d, e;
		scanf("%d%d%d%d", &b, &c, &d, &e);
		printf("%d\n", get_ans(b,c,d,e,tree));
	}
	return 0;
}