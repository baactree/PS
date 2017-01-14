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
int ans[100001];
extern inline bool isprime(int num) {
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	for (int i = 2; i*i < num; i++) {
		if (num%i == 0)
			return false;
	}
	return true;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		memset(ans, 0, sizeof(ans));
		scanf("%d", &N);
		int T = N;
		for (int i = 2; i <= N; i++)
			if (isprime(i)) {
				while (N%i == 0) {
					ans[i]++;
					N /= i;
				}
			}
		for (int i = 2; i <= T; i++) {
			if (ans[i] > 0)
				printf("%d %d\n", i, ans[i]);
		}
	}
	return 0;
}