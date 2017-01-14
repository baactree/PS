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

int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int arr[3];
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		sort(arr, arr + 3);
		if (arr[0] == arr[2])
			ans = max(ans, 10000 + 1000 * arr[0]);
		else if (arr[0] == arr[1] || arr[1] == arr[2])
			ans = max(ans, 1000 + 100 * arr[1]);
		else
			ans = max(ans, 100 * arr[2]);
	}
	printf("%d\n", ans);
	return 0;
}