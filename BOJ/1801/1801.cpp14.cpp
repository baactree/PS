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
int arr[16];
bool dp[71][71][71][71];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	dp[0][0][0][0] = 1;
	for(int i=0;i<N;i++)
		for(int q=70-arr[i];q>=0;q--)
			for(int w=70-arr[i];w>=0;w--)
				for(int e=70-arr[i];e>=0;e--)
					for (int r = 70-arr[i]; r >= 0; r--) {
						if (dp[q][w][e][r]) {
							dp[q + arr[i]][w][e][r] = 1;
							dp[q][w + arr[i]][e][r] = 1;
							dp[q][w][e + arr[i]][r] = 1;
							dp[q][w][e][r + arr[i]] = 1;
						}
					}
	int ans = -1;
	for (int i = 1; i <= 70; i++)
		for (int j = 1; j <= 70; j++)
			if (dp[i][i][j][j])
				ans = max(ans, i*j);
	printf("%d\n", ans);
	return 0;
}