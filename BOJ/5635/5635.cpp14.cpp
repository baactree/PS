/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
struct Node {
	int d, m, y;
	string str;
	Node(const string str,int d,int m,int y):str(str),d(d),m(m),y(y){}
	const bool operator < (const Node& v) {
		if (v.y == y) {
			if (v.m == m) {
				return d > v.d;
			}
			return m > v.m;
		}
		return y > v.y;
	}
};

int main() {
	vector<Node> arr;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a;
		int c, b, d;
		cin >> a >> b >> c >> d;
		arr.push_back({ a,b,c,d });
	}
	sort(arr.begin(), arr.end());
	cout << arr[0].str << endl << arr[N - 1].str << endl;
	return 0;
}