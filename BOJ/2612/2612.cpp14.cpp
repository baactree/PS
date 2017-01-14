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
int N, M;
char a[1001];
char b[1001];
int cache[1001][1001];
int solve(int aidx, int bidx) {
	if (aidx == N&&bidx == M)
		return 0;
	int &ret = cache[aidx][bidx];
	if (ret != INF)
		return ret;
	ret = -INF;
	if (aidx != N&&bidx != M)
		ret = max(ret, solve(aidx + 1, bidx + 1) + ((a[aidx] == b[bidx]) ? 3 : -2));
	if (aidx != N)
		ret = max(ret, solve(aidx + 1, bidx) - 2);
	if (bidx != M)
		ret = max(ret, solve(aidx, bidx + 1) - 2);
	ret = max(ret, 0);
	return ret;
}
pair<string, string> get_ans(int aidx, int bidx) {
	pair<string, string> ret = { "","" };
	if (aidx == N&&bidx == M)
		return ret;
	pair<string, string> temp;
	int temp1, temp2, temp3;
	temp1 = temp2 = temp3 = -INF;
	if (aidx != N&&bidx != M)
		temp1 = solve(aidx + 1, bidx + 1) + ((a[aidx] == b[bidx]) ? 3 : -2);
	if (aidx != N)
		temp2 = solve(aidx + 1, bidx) - 2;
	if (bidx != M)
		temp3 = solve(aidx, bidx + 1) - 2;
	if (temp1 >= temp2&&temp1 >= temp3&&temp1 >= 0) {
		ret.first += a[aidx];
		ret.second += b[bidx];
		temp = get_ans(aidx + 1, bidx + 1);
		ret.first += temp.first;
		ret.second += temp.second;
		return ret;
	}
	else if (temp2 >= temp1&&temp2 >= temp3&&temp2 >= 0) {
		ret.first += a[aidx];
		temp = get_ans(aidx + 1, bidx);
		ret.first += temp.first;
		ret.second += temp.second;
		return ret;
	}
	else if (temp3 >= temp1&&temp3 >= temp2&&temp3 >= 0) {
		ret.second += b[bidx];
		temp = get_ans(aidx, bidx + 1);
		ret.first += temp.first;
		ret.second += temp.second;
		return ret;
	}
	return ret;
}
int main() {
	memset(cache, 0x3f, sizeof(cache));
	scanf("%d%s%d%s", &N, a, &M, b);
	int ans = 0;
	int aidx, bidx;
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++) {
			int temp = solve(i, j);
			if (ans < temp) {
				ans = temp;
				aidx = i;
				bidx = j;
			}
		}
	printf("%d\n", ans);
	pair<string, string> ansp = get_ans(aidx, bidx);
	cout << ansp.first << '\n' << ansp.second << '\n';
	return 0;
}