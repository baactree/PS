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
int cache[21][21][21];
int search(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return search(20, 20, 20);
	int &ret = cache[a][b][c];
	if (ret != -1)
		return ret;
	if (a < b&&b < c)
		return ret = search(a, b, c - 1) + search(a, b - 1, c - 1) - search(a, b - 1, c);
	else
		return ret = search(a - 1, b, c) + search(a - 1, b - 1, c) +search(a-1,b,c-1)- search(a - 1, b - 1, c - 1);
}
int main() {
	while (true) {
		memset(cache, -1, sizeof(cache));
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == b&&b == c&&a == -1)
			break;
		printf("w(%d, %d, %d) = %d\n",a,b,c, search(a, b, c));
	}
	return 0;
}