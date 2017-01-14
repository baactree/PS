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
int arr[100000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int ans = 0;
	int now = -1;
	int len = 0;
	for (int i = 0; i < N; i++) {
		if (now <= arr[i]) {
			len++;
			ans = max(ans, len);
			now = arr[i];
		}
		else {
			len = 1;
			now = arr[i];
		}
	}
	now = 10;
	len = 0;
	for (int i = 0; i < N; i++) {
		if (now >= arr[i]) {
			len++;
			ans = max(ans, len);
			now = arr[i];
		}
		else {
			len = 1;
			now = arr[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}