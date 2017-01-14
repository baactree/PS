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
	int tc;
	cin >> tc;
	while (tc--) {
		int N;
		scanf("%d", &N);
		vector<int> arr(N);
		int sum = 0;
		int max_value = -1;
		int max_idx;
		int max_cnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
			if (arr[i] > max_value) {
				max_cnt = 1;
				max_idx = i;
				max_value = arr[i];
			}
			else if (arr[i] == max_value) {
				max_cnt++;
			}
		}
		if (max_cnt > 1)
			printf("no winner\n");
		else if (max_value > sum / 2)
			printf("majority winner %d\n", max_idx + 1);
		else
			printf("minority winner %d\n", max_idx + 1);

	}
	return 0;
}