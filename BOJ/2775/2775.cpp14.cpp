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
int K, N;
int arr[15][15];
int solve(int x, int y) {
	int ret = 0;
	for (int i = 1; i <= y; i++)
		ret += arr[x - 1][i];
	return ret;
}
int main() {
	for (int i = 1; i < 15; i++)
		arr[0][i] = i;
	for(int i=1;i<15;i++)
		for (int j = 1; j < 15; j++) 
			arr[i][j] = solve(i, j);
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &K, &N);
		printf("%d\n", arr[K][N]);
	}
	return 0;
}