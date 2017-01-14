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
string str;
int cache[100][100];
int solve(int le,int ri) {
	if (le == ri + 1)
		return 1;
	if (le >= ri)
		return 0;
	int &ret = cache[le][ri];
	if (ret != -1)
		return ret;
	ret = 0;
	if (str[le] == '('&&str[ri] == ')')
		ret = max(ret, solve(le + 1, ri - 1)*2);
	if (str[le] == '['&&str[ri] == ']')
		ret = max(ret, solve(le + 1, ri - 1)*3);
	for (int i = le; i < ri; i++) {
		int a = solve(le, i);
		int b = solve(i + 1, ri);
		if(a!=0&&b!=0)
			ret = max(ret, a + b);
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> str;
	printf("%d\n", solve(0,str.size()-1));
	return 0;
}