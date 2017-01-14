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
int tree[100003];
int sum(int pos) {
	pos++;
	int ret = 0;
	while (pos > 0) {
		ret += tree[pos];
		pos -= (pos & -pos);
	}
	return ret;
}
void add(int pos, int val) {
	pos++;
	while (pos < 100003) {
		tree[pos] += val;
		pos += (pos&-pos);
	}
}
int n;
int main() {
	scanf("%d", &n);
	int l, r;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &l, &r);
		int left = sum(l);
		int right = sum(r);
		add(l, -left);
		add(l + 1, left+1);
		add(r, -right-1);
		add(r + 1, right);
		printf("%d\n", left+right);
	}
	return 0;
}