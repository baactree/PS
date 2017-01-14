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
int H, W;
char mat[11][12];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &H, &W);
		for (int i = 0; i < H; i++)
			scanf("%s", mat[i]);
		for (int i = 0; i < H; i++)
			reverse(mat[i], mat[i] + W);
		for (int i = 0; i < H; i++)
			printf("%s\n", mat[i]);
	}
	return 0;
}