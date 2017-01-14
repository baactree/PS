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
int arr[100000];
int N;
int main() {
	scanf("%d", &N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		arr[i + N] = arr[i];
	}
	int head, tail, now;
	head = tail = now = 0;
	int ans = 0;
	while (true) {
		if (head == 2 * N || tail == 2 * N)
			break;
		if (arr[tail] * 2 > sum) {
			tail++;
			head = tail;
			now = 0;
		}
		else if ((now + arr[tail]) * 2 <= sum) {
			now += arr[tail];
			tail++;
		}
		else if ((now + arr[tail]) * 2 > sum) {
			now -= arr[head];
			head++;
		}
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}