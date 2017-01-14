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
int arr[310];
int cache[310][310];
int N, M;
int F;
int solve(int idx, int group) {
	if (idx == N) {
		if(group==M)
			return 1;
		return 0;
	}
	if (group == M)
		return 0;
	int &ret = cache[idx][group];
	if (ret != -1)
		return ret;
	ret = 0;
	int sum = 0;
	for (int i = idx; i < N; i++) {
		sum += arr[i];
		if (sum <= F) 
			ret |= solve(i + 1, group + 1);
	}
	return ret;
}
bool possi(int num) {
	memset(cache, -1, sizeof(cache));
	F = num;
	int ret = solve(0, 0);
	return ret > 0;
}
void get_solve(int idx,int group,vector<int> &vec) {
	int sum = 0;
	for (int i = idx; i < N; i++) {
		sum += arr[i];
		if (sum <= F) {
			if (solve(i + 1, group + 1) > 0) {
				vec.push_back(i - idx + 1);
				get_solve(i + 1, group + 1, vec);
				return;
			}
		}
	}
}
vector<int> get_ans(int t) {
	F = t;
	memset(cache, -1, sizeof(cache));
	solve(0, 0);
	vector<int> ret;
	get_solve(0,0,ret);
	return ret;
}
int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int le, ri, mid;
	le = 1; ri = 30010;
	int ans;
	while (ri >= le) {
		mid = (le + ri) / 2;
		if (possi(mid)) {
			ans = mid;
			ri = mid - 1;
		}
		else
			le = mid + 1;
	}
	printf("%d\n", ans);
	vector<int> gans = get_ans(ans);
	for (int i = 0; i < gans.size(); i++)
		printf("%d ", gans[i]);
	printf("\n");
	return 0;
}