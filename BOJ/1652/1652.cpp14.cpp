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
int N;
char mat[100][101];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	int r, c;
	r = c = 0;
	for(int i=0;i<N;i++)
		for (int j = 0; j + 1 < N; j++) {
			if (mat[i][j] == '.'&&mat[i][j + 1] == '.') {
				r++;
				while (j + 1 < N&&mat[i][j] == '.')
					j++;
			}
		}
	for (int i = 0; i<N; i++)
		for (int j = 0; j + 1 < N; j++) {
			if (mat[j][i] == '.'&&mat[j + 1][i] == '.') {
				c++;
				while (j + 1 < N&&mat[j][i] == '.')
					j++;
			}
		}
	printf("%d %d\n", r, c);
	return 0;
}