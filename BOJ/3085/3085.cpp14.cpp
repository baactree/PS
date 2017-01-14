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
char mat[50][51];
int ans;
bool trip[2][50][50];
void calc() {
	memset(trip, 0, sizeof(trip));
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			int temp = 0;
			for (int k = i; k < N; k++) {
				if (!trip[0][k][j] && mat[k][j] == mat[i][j])
					temp++, trip[0][k][j] = true;
				else
					break;
			}
			ans = max(ans, temp);
			temp = 0;
			for (int k = j; k < N; k++) {
				if (!trip[1][i][k] && mat[i][k] == mat[i][j])
					temp++, trip[1][i][k] = true;
				else
					break;
			}
			ans = max(ans, temp);
		}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	for(int i=0;i<N;i++)
		for (int j = 0; j < N - 1; j++) {
			if (i<N-1&&mat[i][j] != mat[i + 1][j]) {
				swap(mat[i][j], mat[i + 1][j]);
				calc();
				swap(mat[i][j], mat[i + 1][j]);
			}
			if (mat[i][j] != mat[i][j + 1]) {
				swap(mat[i][j], mat[i][j+1]);
				calc();
				swap(mat[i][j], mat[i][j+1]);
			}
		}
	printf("%d\n", ans);
	return 0;
}