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
int X;
string str;
int cache[100][100][100][3];
int solve(int idx, int m, int w, int wait) {
	if (abs(m - w) > X)
		return -INF;
	if (idx == str.size())
		return 0;
	int &ret = cache[idx][m][w][wait];
	if (ret != -1)
		return ret;
	ret = 0;
	if (wait == 1) 
		ret = max(ret, solve(idx, m + 1, w, 0) + 1);
	if (wait == 2)
		ret = max(ret, solve(idx, m, w + 1, 0) + 1);
	if (wait == 0) {
		if (str[idx] == 'M')
			ret = max(ret, solve(idx + 1, m, w, 1));
		else
			ret = max(ret, solve(idx + 1, m, w, 2));
	}
	if (str[idx] == 'M')
		ret = max(ret, solve(idx + 1, m + 1, w, wait) + 1);
	else
		ret = max(ret, solve(idx + 1, m, w + 1, wait) + 1);
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &X);
	cin >> str;
	printf("%d\n", solve(0, 0, 0, 0));
	return 0;
}