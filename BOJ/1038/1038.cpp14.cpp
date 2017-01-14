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
vector<ll> arr;
void solve(int idx, int pre,string str) {
	if (idx == 0) {
		arr.push_back(stoll(str));
		return;
	}
	for (int i = 0; i < pre; i++)
		solve(idx - 1, i, str+to_string(i));
	return;
}
int main() {
	for (int i = 1; i <= 10; i++)
		solve(i, 10,"");
	sort(arr.begin(), arr.end());
	int N;
	scanf("%d", &N);
	if (N < arr.size())
		cout << arr[N] << endl;
	else
		cout << -1 << endl;
	return 0;
}