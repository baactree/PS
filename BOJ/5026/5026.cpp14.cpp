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
	scanf("%d", &tc);
	while (tc--) {
		string arr;
		cin >> arr;
		if (arr == "P=NP") {
			cout << "skipped\n";
			continue;
		}
		string left, right;
		bool flag = false;
		for (int i = 0; i < arr.size(); i++)
			if (arr[i] == '+')
				flag = true;
			else if (flag)
				right += arr[i];
			else
				left += arr[i];
		printf("%d\n", stoi(right) + stoi(left));
	}
	return 0;
}