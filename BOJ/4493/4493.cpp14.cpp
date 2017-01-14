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
	cin >> tc;
	while (tc--) {
		int N;
		scanf("%d", &N);
		int A, B;
		A = B = 0;
		for (int i = 0; i < N; i++) {
			char input[2][2];
			scanf("%s%s", input[0], input[1]);
			if (input[0][0] == 'R') {
				if (input[1][0] == 'P')
					B++;
				else if (input[1][0] == 'S')
					A++;
			}
			else if (input[0][0] == 'P') {
				if (input[1][0] == 'R')
					A++;
				else if (input[1][0] == 'S')
					B++;
			}
			else if (input[0][0] == 'S') {
				if (input[1][0] == 'R')
					B++;
				else if (input[1][0] == 'P')
					A++;
			}
		}
		printf("%s\n", A == B ? "TIE" : A > B ? "Player 1" : "Player 2");
	}
	return 0;
}