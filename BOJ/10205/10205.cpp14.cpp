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
	int Case;
	cin >> Case;
	int tc = 1;
	while (Case--) {
		int N;
		string input;
		cin >> N >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == 'c')
				N++;
			else
				N--;
		}
		printf("Data Set %d:\n", tc++);
		printf("%d\n", N);
		printf("\n");
	}
	return 0;
}