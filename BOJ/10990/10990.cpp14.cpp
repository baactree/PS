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
	int N;
	scanf("%d", &N);
	int B = N - 1;
	for (int i = 1; i <= N; i++,B--) {
		for (int j = 0; j < B; j++)
			printf(" ");
		int cnt = i * 2 - 1 - 2;
		printf("*");
		for (int j = 0; j < cnt; j++)
			printf(" ");
		if (i == 1) {
			printf("\n");
			continue;
		}
		printf("*\n");
	}
	return 0;
}