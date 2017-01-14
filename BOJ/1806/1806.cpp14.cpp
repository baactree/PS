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
int S;
int main() {
	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int head, tail;
	head = tail = 0;
	int sum = 0;
	int ans = INF;
	while (tail!=N) {
		if (sum + arr[tail] < S) {
			sum += arr[tail];
			tail++;
		}
		else {
			ans = min(ans, tail - head + 1);
			sum -= arr[head];
			head++;
		}
		sum = max(0, sum);
		tail = max(tail, head);
	}
	printf("%d\n", ans==INF?0:ans);
	return 0;
}