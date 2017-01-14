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
bool go(int a, int b, int c) {
	if (b + c == a) {
		printf("%d=%d+%d\n", a, b, c);
		return true;
	}
	if (b - c == a) {
		printf("%d=%d-%d\n", a, b, c);
		return true;
	}
	if (b * c == a) {
		printf("%d=%d*%d\n", a, b, c);
		return true;
	}
	if ((double)b / c == a) {
		printf("%d=%d/%d\n", a, b, c);
		return true;
	}
	return false;
}
bool go2(int a, int b, int c) {
	if (a + b == c) {
		printf("%d+%d=%d\n", a, b, c);
		return true;
	}
	if (a - b == c) {
		printf("%d-%d=%d\n", a, b, c);
		return true;
	}
	if (a * b == c) {
		printf("%d*%d=%d\n", a, b, c);
		return true;
	}
	if ((double)a / b == c) {
		printf("%d/%d=%d\n", a, b, c);
		return true;
	}
	return false;
}
void solve(int a, int b, int c) {
	if (go(a, b, c))
		return;
	go2(a, b, c);
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	solve(a, b, c);
	return 0;
}