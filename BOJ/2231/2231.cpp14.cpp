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
int arr[1000001];
int trans(int num) {
	int ret = num;
	while (num) {
		ret += num % 10;
		num /= 10;
	}
	return ret;
}
int main() {
	memset(arr, 0x3f, sizeof(arr));
	for (int i = 1; i <= 1000000; i++) {
		int k = trans(i);
		if (k >= 1 && k <= 1000000)
			arr[k] = min(arr[k], i);
	}
	int N;
	scanf("%d", &N);
	printf("%d\n", arr[N] == INF ? 0 : arr[N]);
	return 0;
}