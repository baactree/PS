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
string N, M;
llu mark[255];
const llu mod = 3987654313;
int prime[30];
llu perm[255];
bool isprime(int x) {
	if (x == 2)
		return true;
	for (int i = 2; i*i <= x; i++)
		if (x%i == 0)
			return false;
	return true;
}
llu p(llu a, llu b) {
	if (b == 0)
		return 1;
	llu temp = p(a, b / 2);
	if (b & 1) {
		return (((temp*temp) % mod)*a) % mod;
	}
	return (temp*temp) % mod;
}
int cnt[2500][26];
int now[26];
bool cmp(const pii& a, const pii& b) {
	return a.first < b.first;
}
bool possi(int k) {
	for (int i = 0; i < 26; i++)
		if (cnt[k][i] != now[i])
			return false;
	return true;
}
int main() {
	cin >> N >> M;
	if (N.size() < M.size()) {
		swap(N, M);
	}
	int pp = 0;
	for (int i = 2;; i++) {
		if (isprime(i)) {
			prime[pp] = i;
			pp++;
		}
		if (pp == 26)
			break;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		mark[i] = prime[i - 'a'];
		perm[i] = p(mark[i], mod - 2);
	}
	int ans = 0;
	for (int i = M.size(); i > 0; i--) {
		memset(cnt, 0, sizeof(cnt));
		llu H = 1;
		vector<pii> vec;
		for (int j = 0; j + i < M.size() + 1; j++) {
			if (j == 0) {
				for (int k = 0; k < i; k++) {
					H = (H*mark[M[k]]) % mod;
					cnt[j][M[k] - 'a']++;
				}
			}
			else {
				for (int k = 0; k < 26; k++)
					cnt[j][k] = cnt[j - 1][k];
				H = (H * perm[M[j - 1]])%mod;
				H = (H*mark[M[j + i - 1]])%mod;
				cnt[j][M[j - 1] - 'a']--;
				cnt[j][M[j + i - 1] - 'a']++;
			}
			vec.push_back({ H,j });
		}
		H = 1;
		sort(all(vec));
		memset(now, 0, sizeof(now));
		for (int j = 0; j + i < N.size() + 1; j++) {
			if (j == 0) {
				for (int k = 0; k < i; k++) {
					H = (H*mark[N[k]]) % mod;
					now[N[k] - 'a']++;
				}
			}
			else {
				H = (H*perm[N[j - 1]])%mod;
				H = (H*mark[N[j + i - 1]])%mod;
				now[N[j - 1] - 'a']--;
				now[N[j + i - 1] - 'a']++;
			}
			pii temp = { H,0 };
			auto p = equal_range(vec.begin(), vec.end(), temp, cmp);
			for (int k = p.first - vec.begin(); k < p.second - vec.begin(); k++) {
				if (possi(vec[k].second)) {
					printf("%d\n", i);
					return 0;
				}
			}
		}
	}
	printf("0\n", ans);
	return 0;
}