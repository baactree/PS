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
	int n;
	vector<int> arr;
	vector<int>::iterator it;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int in;
		scanf("%d", &in);
		it = lower_bound(arr.begin(), arr.end(), in);
		if (it == arr.end())
			arr.push_back(in);
		else
			*it = in;
	}
	printf("%d\n", arr.size());
	return 0;
}