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
struct Node {
	int x, y, a, b, i;
	Node *A, *B, *C, *D;
	Node() {
		A = B = C = D = NULL;
	}
	void del() {
		if (A)
			A->D = D;
		if (B)
			B->C = C;
		if (C)
			C->B = B;
		if (D)
			D->A = A;
	}
};
int N, K;
string str;
Node arr[100000];
struct dt {
	int i, x, y;
	dt(int i,int x,int y):i(i),x(x),y(y){}
};
vector<int> k_num_a;
vector<int> k_num_b;
vector<vector<dt> > k_map_a;
vector<vector<dt> > k_map_b;
bool cmp(const dt& a, const dt& b) {
	return a.x < b.x;
}
void makegraph() {
	//차라리 k인값들을 저장해서 일직선순이 나오게 소팅하면 좌우값들을 빨리찾겟네;
	sort(k_num_a.begin(), k_num_a.end());
	sort(k_num_b.begin(), k_num_b.end());
	k_num_a.erase(unique(k_num_a.begin(), k_num_a.end()), k_num_a.end());
	k_num_b.erase(unique(k_num_b.begin(), k_num_b.end()), k_num_b.end());
	k_map_a.resize(k_num_a.size());
	k_map_b.resize(k_num_b.size());
	for (int i = 0; i < N; i++) {
		int a_idx = lower_bound(k_num_a.begin(), k_num_a.end(), arr[i].a) - k_num_a.begin();
		int b_idx = lower_bound(k_num_b.begin(), k_num_b.end(), arr[i].b) - k_num_b.begin();
		int x = arr[i].x;
		int y = arr[i].y;
		k_map_a[a_idx].push_back({ i,x,y });
		k_map_b[b_idx].push_back({ i,x,y });
	}
	for (int i = 0; i < k_map_a.size(); i++)
		sort(k_map_a[i].begin(), k_map_a[i].end(), cmp);
	for (int i = 0; i < k_map_b.size(); i++)
		sort(k_map_b[i].begin(), k_map_b[i].end(), cmp);
	for (int i = 0; i < k_map_a.size(); i++)
		for (int j = 0; j < k_map_a[i].size(); j++) {
			int now = k_map_a[i][j].i;
			if (j != 0) {
				int front = k_map_a[i][j - 1].i;
				arr[now].C = &arr[front];
			}
			if (j + 1 != k_map_a[i].size()) {
				int back = k_map_a[i][j + 1].i;
				arr[now].B = &arr[back];
			}
		}
	for (int i = 0; i < k_map_b.size(); i++)
		for (int j = 0; j < k_map_b[i].size(); j++) {
			int now = k_map_b[i][j].i;
			if (j != 0) {
				int front = k_map_b[i][j - 1].i;
				arr[now].D = &arr[front];
			}
			if (j + 1 != k_map_b[i].size()) {
				int back = k_map_b[i][j + 1].i;
				arr[now].A = &arr[back];
			}
		}
}
int main() {
	scanf("%d%d", &N, &K);
	cin >> str;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &arr[i].x, &arr[i].y);
		int a= arr[i].x + arr[i].y;
		int b= arr[i].y - arr[i].x;
		arr[i].a = a;
		arr[i].b = b;
		arr[i].i = i;
		k_num_a.push_back(a);
		k_num_b.push_back(b);
	}
	makegraph();
	int len = str.size();
	int now = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'A') {
			if (arr[now].A) {
				int temp = now;
				now = arr[now].A->i;
				arr[temp].del();
			}
		}
		else if (str[i] == 'B') {
			if (arr[now].B) {
				int temp = now;
				now = arr[now].B->i;
				arr[temp].del();
			}
		}
		else if (str[i] == 'C') {
			if (arr[now].C) {
				int temp = now;
				now = arr[now].C->i;
				arr[temp].del();
			}
		}
		else {
			if (arr[now].D) {
				int temp = now;
				now = arr[now].D->i;
				arr[temp].del();
			}
		}
	}
	printf("%d %d\n", arr[now].x, arr[now].y);
	return 0;
}