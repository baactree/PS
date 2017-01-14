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
vector<int> arr;
int main() {
	arr.push_back(0);
	arr.push_back(1);
	while (arr.back() <= 1e9) {
		arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
	}
	arr.pop_back();
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		scanf("%d", &N);
		vector<int> ans;
		for (int i = arr.size() - 1; i >= 0&&N!=0; i--) {
			if (arr[i] <= N) {
				N -= arr[i];
				ans.push_back(arr[i]);
			}
		}
		sort(all(ans));
		for (auto n : ans)
			printf("%d ", n);
		printf("\n");
	}
	return 0;
}