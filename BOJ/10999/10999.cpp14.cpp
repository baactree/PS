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
	ll value, update;
	Node(){}
	Node(ll value,ll update):value(value),update(update){}
	Node operator + (const Node& rhs)const {
		return{ value + rhs.value,update + rhs.update };
	}
};
struct Tree {
	int n;
	vector<Node> tree;
	Tree(int n) :n(n) {
		tree.resize(n * 4);
	}
	Node init(const vector<ll> &arr, int left, int right, int node) {
		if (left == right)
			return tree[node] = { arr[left],0 };
		int mid = (left + right) / 2;
		return tree[node] = init(arr, left, mid, node * 2) + init(arr, mid + 1, right, node * 2 + 1);
	}
	void init(const vector<ll> &arr) {
		init(arr, 0, n - 1, 1);
	}
	void update(int left, int right, int value, int nodeleft, int noderight, int node) {
		if (left > noderight || right < nodeleft)
			return;
		if (left <= nodeleft&&noderight <= right) {
			tree[node].update += value;
			return;
		}
		int mid = (nodeleft + noderight) / 2;
		update(left, right, value, nodeleft, mid, node * 2);
		update(left, right, value, mid + 1, noderight, node * 2 + 1);
		tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value + tree[node * 2].update*(mid - nodeleft + 1) + tree[node * 2 + 1].update*(noderight - mid);
	}
	void update(int left, int right, int value) {
		update(left, right, value, 0, n - 1, 1);
	}
	ll query(int left, int right, int nodeleft, int noderight, int node,int update) {
		tree[node].update += update;
		if (left > noderight || right < nodeleft)
			return 0;
		if (left <= nodeleft&&noderight <= right) 
			return tree[node].value + tree[node].update*(noderight - nodeleft + 1);
		int mid = (nodeleft + noderight) / 2;
		int nextupdate = tree[node].update;
		tree[node].update = 0;
		ll leftret = query(left, right, nodeleft, mid, node * 2, nextupdate);
		ll rightret = query(left, right, mid + 1, noderight, node * 2 + 1, nextupdate);
		tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value + tree[node * 2].update*(mid - nodeleft + 1) + tree[node * 2 + 1].update*(noderight - mid);
		return leftret + rightret;
	}
	ll query(int left, int right) {
		return query(left, right, 0, n - 1, 1, 0);
	}
};
int main(){
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	vector<ll> arr(N);
	for (int i = 0; i < N; i++) 
		scanf("%lld", &arr[i]);
	Tree tree(N);
	tree.init(arr);
	for (int i = 0; i < M + K; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c, d;
			scanf("%d%d%d", &b, &c, &d);
			tree.update(b-1, c-1, d);
		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", tree.query(b-1, c-1));
		}
	}
	return 0;
}