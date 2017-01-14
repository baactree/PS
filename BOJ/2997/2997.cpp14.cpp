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
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);
	if (arr[0] + arr[2] == arr[1] * 2) {
		printf("%d\n", arr[2] + arr[1] - arr[0]);
	}
	else {
		if ((arr[1] - arr[0]) * 2 == arr[2] - arr[1])
			printf("%d\n", arr[1] + arr[1] - arr[0]);
		else
			printf("%d\n", arr[0] + arr[2] - arr[1]);
	}
	return 0;
}