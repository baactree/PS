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
struct Node {
	int s, i, p;
};
Node arr[100];
int N;
int cache[1002][1002];
int solve(int S , int I) {
	if (S == 1000 || I == 1000)
		return N;
	int &ret = cache[S][I];
	if (ret != -1)
		return ret;
	int point = 0;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].s <= S || arr[i].i <= I) {
			point += arr[i].p;
			ret++;
		}
	}
	point -= (S + I- 2);
	if (point > 0) {
		ret = max(ret, solve(S + 1, I));
		ret = max(ret, solve(S, I + 1));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d", &arr[i].s, &arr[i].i, &arr[i].p);
	printf("%d\n", solve(1, 1));
	return 0;
}