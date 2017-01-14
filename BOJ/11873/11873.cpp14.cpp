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
int hi[1002];
int mat[1000][1000];
int N, M;
char buf[1 << 17];
int idx, nidx;
static inline char read() {
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
static inline int readInt() {
	int num = 0;
	char now = read();
	while (now == ' ' || now == '\n')
		now = read();
	while (now != ' '&&now != '\n') {
		num = num * 10 + now - '0';
		now = read();
	}
	return num;
}
int solve() {
	stack<int> st;
	int ret = 0;
	for (int i = 0; i < M + 1; i++) {
		while (!st.empty() && hi[st.top()] >= hi[i]) {
			int j = st.top();
			st.pop();
			int w = -1;
			if (st.empty())
				w = i;
			else
				w = (i - st.top() - 1);
			ret = max(ret, hi[j] * w);
		}
		st.push(i);
	}
	return ret;
}
int main() {
	while (true) {
		memset(hi, 0, sizeof(hi));
		N = readInt();
		M = readInt();
		if (N == M&&N == 0)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				mat[i][j] = readInt();
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (mat[i][j] == 0)
					hi[j] = 0;
				else
					hi[j]++;
			int temp = solve();
			ans = max(ans, temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}