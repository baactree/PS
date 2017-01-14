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
bool p(const vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != arr[arr.size() - i - 1])
			return false;
	}
	return true;
}
bool possi(int n, int k) {
	vector<int> arr;
	while (n) {
		arr.push_back(n%k);
		n /= k;
	}
	if (p(arr))
		return true;
	return false;
}
bool solve(int n) {
	for (int i = 2; i <= 64; i++) 
		if (possi(n, i))
			return true;
	return false;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		cin >> N;
		printf("%d\n", solve(N));
	}
	return 0;
}