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
int N, M;
int mat[100][100];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &mat[i][j]);
		int ans = 0;
		for(int k=0;k<M;k++)
			for(int i=0;i<N;i++)
				for(int j=i+1;j<N;j++)
					if (mat[i][k] > mat[j][k]) {
						swap(mat[i][k], mat[j][k]);
						ans += j - i;
					}
		printf("%d\n", ans);
	}
	return 0;
}
