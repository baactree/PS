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
int N;
extern inline bool possi(const string & str) {
	if (str.size() == 1)
		return true;
	int d = str[1] - str[0];
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i + 1] - str[i] != d)
			return false;
	}
	return true;
}
int main() {
	scanf("%d", &N);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		string temp = to_string(i);
		if (possi(temp))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}