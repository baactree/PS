/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef vector<vector<pair<int, int> > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pair<int, int> > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int mat[101][101];
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	memset(mat, 0x3f, sizeof(mat));
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		mat[a][b] = 1;
	}
	for (int i = 1; i <= N; i++)
		mat[i][i] = 0;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (i == k || j == k)
					continue;
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (mat[i][j] == 0x3f3f3f3f&&mat[j][i]==0x3f3f3f3f)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}