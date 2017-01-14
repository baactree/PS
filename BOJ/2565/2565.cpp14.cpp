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
pii arr[100];
int N;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr + N);
	vector<int> lis;
	for (int i = 0; i < N; i++) {
		auto it = upper_bound(lis.begin(), lis.end(), arr[i].second);
		if (it != lis.end())
			*it = arr[i].second;
		else
			lis.push_back(arr[i].second);
	}
	printf("%d\n", N - lis.size());
	return 0;
}