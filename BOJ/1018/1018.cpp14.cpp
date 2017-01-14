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
char mat[50][51];
int calc(int x, int y) {
	int ret = 0;
	int cnt = 0;
	for(int i=0;i<8;i++)
		for (int j = 0; j < 8; j++) {
			if ((i+j)& 1) {
				if (mat[i + x][j + y] == 'W')
					ret++;
			}
			else
				if (mat[i + x][j + y] == 'B')
					ret++;
		}
	int temp = 0;
	cnt = 1;
	for(int i=0;i<8;i++)
		for (int j = 0; j < 8; j++) {
			if ((i+j) & 1) {
				if (mat[i + x][j + y] == 'B')
					temp++;
			}
			else
				if (mat[i + x][j + y] == 'W')
					temp++;
			
		}
	return min(ret, temp);
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	int ans = INF;
	for(int i=0;i<=N-8;i++)
		for (int j = 0; j <= M-8; j++) {
			int cnt = calc(i, j);
			ans = min(ans, cnt);
		}
	printf("%d\n", ans);
	return 0;
}