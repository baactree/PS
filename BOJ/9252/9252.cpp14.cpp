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
int cache[1005][1005];
string A, B;
int la, lb;
int solve(int aidx, int bidx) {
	if (aidx == la&&bidx == lb)
		return 0;
	int &ret = cache[aidx][bidx];
	if (ret != -1)
		return ret;
	ret = 0;
	if (aidx != la)
		ret = max(ret, solve(aidx + 1, bidx));
	if (bidx != lb)
		ret = max(ret, solve(aidx, bidx + 1));
	if (aidx != la&&bidx != lb)
		if (A[aidx] == B[bidx])
			ret = max(ret, solve(aidx + 1, bidx + 1) + 1);
	return ret;
}
string get_ans(int aidx, int bidx) {
	if (aidx == la&&bidx == lb)
		return "";
	int temp[3];
	for (int i = 0; i < 3; i++)
		temp[i] = -1;
	if (aidx != la)
		temp[0] = solve(aidx + 1, bidx);
	if (bidx != lb)
		temp[1] = solve(aidx, bidx + 1);
	if (aidx != la&&bidx != lb)
		if (A[aidx] == B[bidx])
			temp[2] = solve(aidx + 1, bidx + 1) + 1;
	if (temp[0] >= max(temp[1], temp[2]))
		return get_ans(aidx + 1, bidx);
	if (temp[1] >= max(temp[0], temp[2]))
		return get_ans(aidx, bidx + 1);
	return A[aidx]+get_ans(aidx + 1, bidx + 1);
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> A >> B;
	la = A.size();
	lb = B.size();
	int ans = solve(0, 0);
	cout << ans << endl << get_ans(0, 0) << endl;
	return 0;
}