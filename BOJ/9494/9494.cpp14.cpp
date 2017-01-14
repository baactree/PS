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
string str[1000];
int main() {
	while (true) {
		int N;
		scanf("%d\n", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			getline(cin, str[i]);
		int r = 0;
		int idx = 0;
		while (r != N) {
			for (; idx < str[r].size(); idx++)
				if (str[r][idx] == ' ')
					break;
			r++;
		}
		printf("%d\n", idx + 1);
	}
	return 0;
}