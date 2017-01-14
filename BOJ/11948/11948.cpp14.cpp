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

int main() {
	int s[4];
	int g[2];
	for (int i = 0; i < 4; i++)
		scanf("%d", &s[i]);
	for (int i = 0; i < 2; i++)
		scanf("%d", &g[i]);
	sort(s, s + 4);
	sort(g, g + 2);
	int sum = 0;
	for (int i = 1; i < 4; i++)
		sum += s[i];
	sum += g[1];
	printf("%d\n", sum);

	return 0;
}