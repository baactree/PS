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
ll N, K;
ll cache[50][50][3];
ll solve(int idx, int ri, int mode) {
	if (idx == N) {
		if (mode!=0)
			return 1;
		return 0;
	}
	ll &ret = cache[idx][ri][mode];
	if (ret != -1)
		return ret;
	ret = 0;
	//현재 까지 만든게 ㄴㄴ 이고 이미 망 한 경우
	if (mode==2) {
		ret += solve(idx + 1, ri + 1, 2);
		ret += solve(idx + 1, ri, 2);
		return ret;
	}
	//현재 까지 만든게 ㄴㄴ 이고 ri만큼 닫으면 가능한 경우
	if (mode == 1) {
		if (ri == 1) 
			ret += solve(idx + 1, 0, 0);
		else if (ri == 0)
			ret += solve(idx + 1, 0, 2);
		else
			ret += solve(idx + 1, ri - 1, 1);
		ret += solve(idx + 1, ri + 1, 1);
		return ret;
	}
	//현재 까지 만든게 ㅇㅇ 인경우
	ret += solve(idx + 1, 1, 1);
	ret += solve(idx + 1, 0, 2);
	return ret;
}
string get_ans(int idx, int ri, int mode, ll k) {
	if (idx == N)
		return "";
	if (mode == 2) {
		ll temp = solve(idx + 1, ri + 1, 2);
		if (k >= temp) {
			k -= temp;
			return ")" + get_ans(idx + 1, ri, 2, k);
		}
		else
			return "(" + get_ans(idx + 1, ri + 1, 2, k);
	}
	if (mode == 1) {
		ll temp = solve(idx + 1, ri + 1, 1);
		if (k >= temp) {
			k -= temp;
			if (ri == 1)
				return ")" + get_ans(idx + 1, 0, 0, k);
			else if (ri == 0)
				return ")" + get_ans(idx + 1, 0, 2, k);
			else
				return ")" + get_ans(idx + 1, ri - 1, 1, k);
		}
		else
			return "(" + get_ans(idx + 1, ri + 1, 1, k);
	}
	ll temp = solve(idx + 1, 1, 1);
	if (k >= temp) {
		k -= temp;
		return ")" + get_ans(idx + 1, 0, 2, k);
	}
	return "(" + get_ans(idx + 1, 1, 1, k);
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%lld%lld", &N, &K);
	ll ans=solve(0, 0, 0);
	if (K > ans - 1)
		printf("-1\n");
	else
		cout << get_ans(0,0,0,K) << endl;
	return 0;
}