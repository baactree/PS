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
int main() {
	int N;
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int input[4];
		for (int j = 0; j < 4; j++)
			scanf("%d", &input[j]);
		sort(input, input + 4);
		if (input[0] == input[1] && input[2] == input[3]) {
			if (input[1] == input[2]) {
				ans = max(ans, 50000 + input[0] * 5000);
			}
			else
				ans = max(ans, 2000 + input[0] * 500 + input[2] * 500);
		}
		else if (input[0] == input[2])
			ans = max(ans, 10000 + input[0] * 1000);
		else if (input[1] == input[3])
			ans = max(ans, 10000 + input[1] * 1000);
		else if (input[0] == input[1] || input[1] == input[2])
			ans = max(ans, input[1] * 100 + 1000);
		else if (input[2] == input[3])
			ans = max(ans, input[2] * 100 + 1000);
		else
			ans = max(ans, input[3] * 100);
	}
	printf("%d\n", ans);
	return 0;
}