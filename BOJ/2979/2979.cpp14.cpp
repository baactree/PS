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
int get_value(int state, int index) {
	return (state >> (index * 2)) & 3;
}
int set_value(int state, int index, int value) {
	return (state&~(3 << (index * 2))) | (value << (index * 2));
}
int sgn(int x) {
	if (!x)
		return 0;
	return x > 0 ? 1 : -1;
}
int incr(int x) {
	if (x < 0)
		return x - 1;
	return x + 1;
}
int c[1 << 24];
int bfs(int n, int begin, int end) {
	if (begin == end)
		return 0;
	memset(c, 0, sizeof(c));
	queue<int> q;
	q.push(begin);
	c[begin] = 1;
	q.push(end);
	c[end] = -1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int top[4] = { -1,-1,-1,-1 };
		for (int i = n - 1; i >= 0; i--)
			top[get_value(here, i)] = i;
		for (int i = 0; i < 4; i++)
			if (top[i] != -1)
				for (int j = 0; j < 4;j++)
					if (i != j && (top[j] == -1 || top[j]>top[i])) {
						int there = set_value(here, top[i], j);
						if (c[there] == 0) {
							c[there] = incr(c[here]);
							q.push(there);
						}
						else if (sgn(c[there]) != sgn(c[here])) {
							return abs(c[there]) + abs(c[here]) - 1;
						}
					}
	}
	return -1;
}
int cnt[101];
int main() {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int j = a; j < b; j++)
			cnt[j]++;
	}
	for (int i = 0; i <= 100; i++) {
		if (cnt[i] == 1)
			ans += arr[0];
		else if (cnt[i] == 2)
			ans += arr[1]*2;
		else if (cnt[i] == 3)
			ans += arr[2]*3;
	}
	cout << ans << endl;
	return 0;
}