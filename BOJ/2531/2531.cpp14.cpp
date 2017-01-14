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
int N, d, k, c;
int arr[60000];
int cnt[3001];
int main() {
	scanf("%d%d%d%d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		arr[i + N] = arr[i];
	}
	int ans = 0;
	int tcnt = 0;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			for (int j = 0; j < k; j++) {
				cnt[arr[j]]++;
				if (cnt[arr[j]] == 1)
					tcnt++;
			}
		}
		else {
			cnt[arr[i - 1]]--;
			if (cnt[arr[i - 1]] == 0)
				tcnt--;
			cnt[arr[i + k - 1]]++;
			if (cnt[arr[i + k - 1]] == 1)
				tcnt++;
		}
		if (cnt[c] == 0) 
			ans = max(ans, tcnt + 1);
		else
			ans = max(ans, tcnt);
	}
	printf("%d\n", ans);
	return 0;
}