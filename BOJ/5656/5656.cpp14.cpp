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
int main() {
	int tc = 1;
	while (true) {
		int a, b;
		char input[5];
		bool flag = false;
		scanf("%d%s%d", &a, input, &b);
		string str = input;
		if (str=="E")
			break;
		if (str == ">")
			flag = a > b;
		if (str == ">=")
			flag = a >= b;
		if (str == "<")
			flag = a < b;
		if (str == "<=")
			flag = a <= b;
		if (str == "==")
			flag = a == b;
		if (str == "!=")
			flag = a != b;
		printf("Case %d: %s\n", tc, flag ? "true" : "false");
		tc++;
	}
	return 0;
}