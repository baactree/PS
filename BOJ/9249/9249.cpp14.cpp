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
string A, B;
llu p[200001];
const int k = 255;
unordered_set<llu> s;
int idx;
bool possi(int x) {
	s.clear();
	llu T = 0;
	for (int i = 0; i + x < A.size() + 1; i++) {
		if (i == 0) {
			for (int j = 0; j < x; j++)
				T = T*k + A[j];
		}
		else
			T = (T - A[i - 1] * p[x])*k + A[i + x - 1];
		s.insert(T);
	}
	T = 0;
	for (int i = 0; i + x < B.size() + 1; i++) {
		if (i == 0) {
			for (int j = 0; j < x; j++)
				T = T*k + B[j];
		}
		else
			T = (T - B[i - 1] * p[x])*k + B[i + x - 1];
		if (s.count(T) != 0) {
			idx = i;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> A >> B;
	p[1] = 1;
	for (int i = 2; i < max(A.size(), B.size()); i++)
		p[i] = p[i - 1] * k;
	int le, ri, mid;
	le = 0;
	ri = min(A.size(), B.size());
	int ans;
	while (ri >= le) {
		mid = (ri + le) / 2;
		if (possi(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	printf("%d\n", ans);
	for (int i = idx; i < idx + ans; i++)
		printf("%c", B[i]);
	printf("\n");
	return 0;
}