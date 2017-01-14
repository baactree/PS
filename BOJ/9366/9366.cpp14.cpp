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
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int arr[3];
		scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
		sort(arr, arr + 3);
		printf("Case #%d: ", tc);
		if (arr[0] + arr[1] <= arr[2]) {
			printf("invalid!\n");
			continue;
		}
		if (arr[0] == arr[2]) {
			printf("equilateral\n");
			continue;
		}
		if (arr[0] == arr[1] || arr[1] == arr[2]) {
			printf("isosceles\n");
			continue;
		}
		printf("scalene\n");
	}
	return 0;
}