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
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int hi[402];
char mat[400][401];
int N, M;
int solve() {
	stack<int> st;
	int ret = 0;
	for (int i = 0; i < M + 1; i++) {
		while (!st.empty() && hi[st.top()] >= hi[i]) {
			int j = st.top();
			st.pop();
			int w;
			if (st.empty())
				w = i;
			else
				w = (i - st.top() - 1);
			ret = max(ret, hi[j] ? (w + hi[j]) * 2 : 0);
		}
		st.push(i);
	}
	return ret;
}
int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", mat[i]);
	int ans = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (mat[i][j] == 'X')
				hi[j] = 0;
			else
				hi[j]++;
		int temp = solve();
		ans = max(ans,temp);
	}
	printf("%d\n", ans - 1);
	return 0;
}