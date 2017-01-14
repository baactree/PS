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
int arr[1000005];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		int M;
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			int in;
			scanf("%d", &in);
			int idx = lower_bound(arr, arr + N, in) - arr;
			if (idx>=0&&idx<N&&arr[idx]==in)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}