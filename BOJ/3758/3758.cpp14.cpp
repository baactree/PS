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
struct Node {
	int id;
	int score[101];
	int t;
	int cnt;
	int sum;
	Node() {
		memset(score, 0, sizeof(score));
		t = 0;
		cnt = 0;
		sum = 0;
	}
	void init() {
		memset(score, 0, sizeof(score));
		t = cnt = sum = 0;
	}
	void calc() {
		for (int i = 0; i <= 100; i++)
			sum += score[i];
	}
	const bool operator < (Node &rhs)const {
		if (sum == rhs.sum) {
			if (cnt == rhs.cnt) {
				return t < rhs.t;
			}
			return cnt < rhs.cnt;
		}
		return sum > rhs.sum;
	}
};
Node arr[101];
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int n, k, t, m;
		scanf("%d%d%d%d", &n, &k, &t, &m);
		for (int i = 1; i <= n; i++) {
			arr[i].id = i;
			arr[i].init();
		}
		for (int i = 1; i <= m; i++) {
			int id, j, s;
			scanf("%d%d%d", &id, &j, &s);
			arr[id].cnt++;
			arr[id].t = i;
			arr[id].score[j] = max(arr[id].score[j], s);
		}
		for (int i = 1; i <= n; i++)
			arr[i].calc();
		sort(arr+1, arr+n+1);
		for (int i = 1; i <= n; i++)
			if (arr[i].id == t)
				printf("%d\n", i);
	}
	return 0;
}