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
int A[400];
int B[400];
int a, b;
int cache[401][401][401];
int solve(int aidx, int bidx, int idx) {
	if (idx == N) {
		if(aidx==a&&bidx==b)
			return 0;
		return -INF;
	}
	int &ret = cache[aidx][bidx][idx];
	if (ret != INF)
		return ret;
	ret = -INF;
	ret = max(ret, solve(aidx, bidx, idx + 1));
	if (aidx != a) {
		ret = max(ret, solve(aidx + 1, bidx, idx + 1));
	}
	if (bidx != b) {
		ret = max(ret, solve(aidx, bidx + 1, idx + 1));
	}
	if (aidx != a&&bidx != b) {
		ret = max(ret, solve(aidx + 1, bidx + 1, idx + 1) + A[aidx] * B[bidx]);
	}
	return ret;
}
int main(){
	memset(cache, 0x3f, sizeof(cache));
	scanf("%d", &N);
	int idx = 0;
	for (int i = 0; i < N; i++) {
		int in;
		scanf("%d", &in);
		if(in!=0)
			A[idx++] = in;
	}
	a = idx;
	idx = 0;
	for (int i = 0; i < N; i++) {
		int in;
		scanf("%d", &in);
		if(in!=0)
			B[idx++] = in;
	}
	b = idx;
	printf("%d\n", solve(0, 0, 0));
	return 0;
}