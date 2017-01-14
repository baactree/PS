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
int arr[8];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 8; i++)
			scanf("%d", &arr[i]);
		printf("%d\n", max(1,arr[0] + arr[4]) + max(1,(arr[1] + arr[5]))*5 + max(0,(arr[2] +arr[6]))*2 + (arr[3] + arr[7])*2);
	}
	return 0;
}