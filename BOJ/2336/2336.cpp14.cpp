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
int tree[500001];
int n;
int sum(int pos) {
	pos++;
	int ret = INF;
	while (pos > 0) {
		ret = min(ret, tree[pos]);
		pos &= (pos - 1);
	}
	return ret;
}
void add(int pos, int val) {
	pos++;
	while (pos < n + 1) {
		tree[pos] = min(tree[pos], val);
		pos += (pos&-pos);
	}
}
int main() {
	memset(tree, 0x3f, sizeof(tree));
	scanf("%d", &n);
	vector<vector<int> >s(n,vector<int>(3));
	for (int i = 0; i < 3; i++)
		for (int j = 0, x; j < n; j++)
			scanf("%d", &x), s[x-1][i] = j;
	sort(s.begin(), s.end());
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (sum(s[i][1])>s[i][2]) 
			ret++;
		add(s[i][1], s[i][2]);
	}
	printf("%d\n", ret);
	return 0;
}