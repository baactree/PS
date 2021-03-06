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
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int main() {
	pii arr[8];
	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i].first), arr[i].second = i;
	sort(arr, arr + 8);
	int sum = 0;
	vector<int> ans;
	for (int i = 7; i > 2; i--) {
		sum += arr[i].first;
		ans.push_back(arr[i].second+1);
	}
	sort(ans.begin(), ans.end());

	cout << sum << endl;
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}