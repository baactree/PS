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
int arr[200];
double cache[200][200];
double table[200][200];
double solve(int idx, int pick) {
	if (idx == N) 
		return 0;
	if (pick == M)
		return 1e9;
	double &ret = cache[idx][pick];
	if (ret != 1e9 + 1)
		return ret;
	ret = 1e9;
	for (int i = idx; i < N; i++) 
		ret = min(ret, solve(i + 1, pick + 1)+table[idx-1][i]);
	return ret;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++)
				cache[i][j] = 1e9 + 1;
		scanf("%d%d", &N,&M);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				double temp = 0;
				for (int k = i + 1; k < j; k++)
					temp += abs(arr[k] - (arr[i] + ((double)arr[j] - arr[i])*((double)k - i) / (j - i)));
				table[i][j] = temp;
			}
		}
		printf("%lf\n", solve(1, 1)/N);
	}
	return 0;
}