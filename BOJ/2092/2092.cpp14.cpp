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
int T, A, S, B;
int ct[201];
int cache[4001][201];
const int mod = 1000000;
int search(int idx,int num) {
	if (num > T)
		return 0;
	if (idx == B)
		return 0;
	int &ret = cache[idx][num];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += search(idx, num + 1);
	ret %= mod;
	for (int i = 1; i <= ct[num] && idx + i <= B; i++) {
		ret += search(idx + i, num + 1);
		if (idx + i >= S&&idx + i <= B)
			ret++;
		ret %= mod;
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d%d", &T, &A, &S, &B);
	for (int i = 0; i < A; i++) {
		int in;
		scanf("%d", &in);
		ct[in]++;
	}
	printf("%d\n", search(0, 1));
	return 0;
}