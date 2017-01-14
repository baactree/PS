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
bool prime[4000001];
vector<int> arr;
int main() {
	int N;
	scanf("%d", &N);
	for(int i=2;i<=4000000;i++)
		if (!prime[i]) {
			arr.push_back(i);
			for (int j = i + i; j <= 4000000; j += i)
				prime[j] = true;
		}
	arr.push_back(INF);
	int sum = 2;
	int st, fi;
	st = fi = 0;
	int ans = 0;
	while (fi >= st) {
		if (sum == N) {
			ans++;
			fi++;
			sum += arr[fi];
		}
		else if (sum < N) {
			fi++;
			sum += arr[fi];
		}
		else {
			sum -= arr[st];
			st++;
		}
	}
	printf("%d\n", ans);
	return 0;
}