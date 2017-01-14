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
bool mat[105][105];
void paint(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			mat[i][j] = 1;
}
int main() {
	for (int i = 0; i < 4; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		paint(x1, y1, x2, y2);
	}

	int ans = 0;
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++)
			if (mat[i][j])
				ans++;
	printf("%d\n", ans);
	return 0;
}