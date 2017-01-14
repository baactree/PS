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
	Node *children[10];
	int terminal;
	Node() :terminal(0) {
		memset(children, 0, sizeof(children));
	}
	~Node() {
		for (int i = 0; i < 10; i++)
			if (children[i])
				delete children[i];
	}
	void insert(const char* key) {
		if (*key == 0)
			terminal = true;
		else {
			int next = *key - '0';
			if (!children[next])
				children[next] = new Node();
			children[next]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == 0)
			return true;
		if (terminal)
			return false;
		return children[*key - '0']->find(key + 1);
	}
};
char str[10000][11];
bool solve(Node *root, int N) {
	for (int i = 0; i < N; i++)
		if (!root->find(str[i]))
			return false;
	return true;
}
int main() {
	int Case;
	cin >> Case;
	while (Case--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%s", str[i]);
		Node *root = new Node();
		for (int i = 0; i < N; i++)
			root->insert(str[i]);
		if (solve(root, N))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

