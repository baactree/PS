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
bool check[10001];
int calc(int num) {
	int ret = num;
	string str = to_string(num);
	for (int i = 0; i < str.size(); i++)
		ret += str[i] - '0';
	return ret;
}
int main() {
	for (int i = 1; i <= 10000; i++) {
		int num = calc(i);
		if (num <= 10000)
			check[num] = true;
	}
	for (int i = 1; i <= 10000; i++)
		if (!check[i])
			printf("%d\n", i);
	return 0;
}