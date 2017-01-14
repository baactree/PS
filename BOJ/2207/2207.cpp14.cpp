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
vector<int> arr;
vector<vector<int> > edge;
vector<vector<int> >A;//가위 양수
vector<vector<int> >B;//바위 음수
void makegraph() {
	int n = arr.size();
	edge.clear();
	edge.resize(n * 2);
	for (int i = 0; i < n; i+=2) {
		int j = i + 1;
		//a가 거짓이면 b는 참
		//b가 거짓이면 a는 참
		edge[i * 2 + 1].push_back(j * 2);
		edge[j * 2 + 1].push_back(i * 2);
		//M인날에 반대선택이 있으면
		//a가 참이면 반대선택들은 거짓
		if (arr[i] > 0) {
			for (auto k : B[arr[i]])
				edge[i * 2].push_back(k * 2 + 1);
		}
		else {
			for (auto k : A[-arr[i]])
				edge[i * 2].push_back(k * 2 + 1);
		}
		//b가 참이면 반대선택들은 거짓
		if (arr[j] > 0) {
			for (auto k : B[arr[j]])
				edge[j * 2].push_back(k * 2 + 1);
		}
		else {
			for (auto k : A[-arr[j]])
				edge[j * 2].push_back(k * 2 + 1);
		}
	}
}
vector<int> scc, discoverd;
int scc_num, vertex_num;
stack<int> st;
int dfs(int here) {
	int ret = discoverd[here] = vertex_num++;
	st.push(here);
	for (auto there : edge[here]) {
		if (discoverd[there] == -1)
			ret = min(ret, dfs(there));
		else if (scc[there] == -1)
			ret = min(ret, discoverd[there]);
	}
	if (ret == discoverd[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			scc[t] = scc_num;
			if (t == here)
				break;
		}
		scc_num++;
	}
	return ret;
}
void makescc() {
	scc = discoverd = vector<int>(edge.size(), -1);
	scc_num = vertex_num = 0;
	for (int i = 0; i < edge.size(); i++)
		if (discoverd[i] == -1)
			dfs(i);
}
string solve() {
	makegraph();
	makescc();
	for (int i = 0; i < edge.size(); i += 2)
		if (scc[i] == scc[i + 1])
			return "OTL\n";
	return "^_^\n";
}
int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	A = B = vector<vector<int> >(M + 1);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr.push_back(a);
		arr.push_back(b);
		if (a > 0)
			A[a].push_back(i * 2);
		else
			B[-a].push_back(i * 2);
		if (b > 0)
			A[b].push_back(i * 2 + 1);
		else
			B[-b].push_back(i * 2 + 1);
	}
	cout << solve();
	return 0;
}